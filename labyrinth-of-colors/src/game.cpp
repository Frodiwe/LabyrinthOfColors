//
//  game.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.11.21.
//

#include "game.hpp"

#include "window.hpp"
#include "di.hpp"

#include <string>

#include "SDL2/SDL.h"

#include "src/consts.h"

#include "src/player_kit.hpp"
#include "src/items_kit.hpp"
#include "src/color_factory_kit.hpp"

#include "src/level/cell_color.h"
#include "src/level/map_kit.hpp"
#include "src/level/level_config.h"

#include "src/coord.hpp"
#include "src/events_queue.hpp"
#include "src/texture.h"
#include "src/events_queue.hpp"
#include "src/view.h"

#include "src/systems/render_system.hpp"
#include "src/systems/movement_system.hpp"

#include "src/components/map_position.h"
#include "src/components/position.h"

#include "src/listeners/move_listener.hpp"
#include "src/listeners/give_base_inventory_listener.hpp"
#include "src/listeners/change_map_opacity.hpp"
#include "src/listeners/handle_exit_listener.hpp"
#include "src/listeners/take_items_listener.hpp"
#include "src/listeners/activate_factory_listener.hpp"
#include "src/listeners/deactivate_factory_listener.hpp"
#include "src/listeners/select_blending_color_listener.hpp"
#include "src/listeners/blend_colors_listener.hpp"

#include "src/events/move_event.h"
#include "src/events/move_in_event.h"
#include "src/events/move_out_event.h"
#include "src/events/player_created_event.h"
#include "src/events/item_given_event.h"
#include "src/events/select_inventory_item_event.h"
#include "src/events/submit_event.h"

#include "src/utils/csv.h"
#include "src/utils/key_value_file.h"

#include "src/level/tags/cell.h"

Game::Game(Window* window, EventsQueue* events_queue): events_queue{events_queue}
{
    subscribe_listeners();
    
    auto config = get_level_config("2");
    
    create_level(config);
    events_queue->publish<PlayerCreatedEvent>(create_player(config.start));
}

void Game::subscribe_listeners()
{
    events_queue->subscribe<PlayerCreatedEvent>(new GiveBaseInventoryListener{
        DI::get_registry(),
        DI::get_events_queue(),
        DI::get_inventory_system(),
        DI::get_items_system(),
        DI::get_items_kit()
    });
    events_queue->subscribe<MoveEvent>(new MoveListener{
        DI::get_registry(),
        DI::get_events_queue(),
        DI::get_player_system(),
        DI::get_movement_system(),
        DI::get_inventory_system(),
        DI::get_items_system()
    });
    events_queue->subscribe<ItemGivenEvent>(new ChangeMapOpacity{
        DI::get_registry()
    });
    events_queue->subscribe<MoveInEvent>(new HandleExitListener{
        DI::get_registry(),
        DI::get_events_queue()
    });
    events_queue->subscribe<MoveInEvent>(new TakeItemsListener{
        DI::get_registry(),
        DI::get_events_queue(),
        DI::get_player_system(),
        DI::get_items_system(),
        DI::get_inventory_system()
    });
    events_queue->subscribe<MoveInEvent>(new ActivateFactoryListener{
        DI::get_registry(),
        DI::get_color_factory_system()
    });
    events_queue->subscribe<MoveOutEvent>(new DeactivateFactoryListener{
        DI::get_registry(),
        DI::get_color_factory_system()
    });
    events_queue->subscribe<SelectInventoryItemEvent>(new SelectBlendingColorListener{
        DI::get_registry(),
        DI::get_color_factory_system(),
        DI::get_inventory_system(),
    });
    events_queue->subscribe<SubmitEvent>(new BlendColorsListener{
        DI::get_registry(),
        DI::get_color_factory_system(),
        DI::get_items_system(),
        DI::get_items_kit(),
        DI::get_inventory_system(),
        DI::get_player_system()
    });
}

LevelConfig Game::get_level_config(const std::string& name) const
{
    const std::string base_dir = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/" + name + "/";
    auto items_file = CSV{base_dir + "level_items"};
    auto items = LevelItems{};
    
    for (const auto& attrs : items_file.read())
    {
        items.emplace_back(attrs[0], Consts::category_map.at(attrs[1]), Consts::color_map.at(attrs[2]), MapPosition{attrs[3] + "," + attrs[4]});
    }
    
    auto actions = KeyValueFile{base_dir + "level_actions"}.read();
    auto color_file = CSV{base_dir + "level_map"};
    
    return {color_file.read(Consts::color_map), items, actions.at("start"), actions.at("exit")};
}

void Game::create_level(LevelConfig config)
{
    DI::get_map_kit()->create_map(config.labyrinth, config.exit);
    
    for (const auto& [item_name, category, color, pos] : config.items)
    {
        DI::get_items_kit()->create_item(item_name, category, color, pos, DI::get_registry().get<Position>(get_cell_at(pos)));
    }
    
    // hardcoded
    DI::get_color_factory_kit()->create_factory({9, 16});
    
    DI::get_movement_system()->move_world_coords(get_cell_at({0, 0}), get_cell_at(config.start));
}

entt::entity Game::create_player(MapPosition start)
{
    return DI::get_player_kit()->create_player({Consts::window_width / 2, Consts::window_height / 2}, start);
}

entt::entity Game::get_cell_at(const MapPosition& at)
{
    for (const auto [entity, map_position] : DI::get_registry().view<Cell, MapPosition>().each())
    {
        if (map_position.i == at.i and map_position.j == at.j)
        {
            return entity;
        }
    }
    
    return entt::null;
}

void Game::render(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	
    DI::get_render_system()->render_map(renderer);
    DI::get_render_system()->render_items(renderer);
    DI::get_render_system()->render_player(renderer);
    DI::get_render_system()->render_inventory(renderer);

	SDL_RenderPresent(renderer);
}

Game::~Game()
{
	return;
}


