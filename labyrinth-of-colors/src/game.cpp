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

#include <SDL2/SDL.h>

#include "src/player_kit.hpp"
#include "src/items_kit.hpp"

#include "src/level/cell_color.h"
#include "src/level/map_kit.hpp"
#include "src/level/level_config.h"

#include "src/coord.hpp"
#include "src/events_queue.hpp"
#include "src/texture.h"
#include "src/events_queue.hpp"

#include "src/systems/render_system.hpp"
#include "src/systems/movement_system.hpp"

#include "src/components/map_position.h"
#include "src/components/position.h"

#include "src/listeners/move_listener.hpp"
#include "src/listeners/give_base_inventory_listener.hpp"

#include "src/events/move_event.h"
#include "src/events/player_created_event.h"

#include "src/utils/csv.h"
#include "src/utils/key_value_file.h"

#include "src/level/tags/cell.h"

LevelConfig Game::get_level_config(const std::string& name) const
{
    const std::string base_dir = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/" + name + "/";
    auto color_file = CSV{base_dir + "level_map"};
    auto items_file = KeyValueFile{base_dir + "level_items"};
        
    auto items = LevelItems{};
    
    for (const auto& [item_name, position_str] : items_file.read())
    {
        items.emplace_back(item_name, ITEMS_COLOR_MAP.at(item_name), MapPosition{position_str});
    }
    
    auto actions = KeyValueFile{base_dir + "level_actions"}.read();
	
    return {color_file.read(COLOR_DECODE_MAP), items, actions.at("start"), actions.at("exit")};
}

Game::Game(Window* window, EventsQueue* events_queue)
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
        DI::get_movement_system(),
        DI::get_inventory_system(),
        DI::get_items_system()
    });
    
	auto config = get_level_config("2");
    
    DI::get_map_kit()->create_map(config.labyrinth, config.exit);
    
    auto player = DI::get_player_kit()->create_player({Coord::start_x, Coord::start_y}, config.start);
    
    events_queue->publish<PlayerCreatedEvent>(player);
    
    for (const auto& [item_name, color, pos] : config.items)
    {
        DI::get_items_kit()->create_item(item_name, color, pos, DI::get_registry().get<Position>(get_cell_at(pos)));
    }
    
    DI::get_movement_system()->move_world_coords(get_cell_at({0, 0}), get_cell_at(config.start));
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

	SDL_RenderPresent(renderer);
}

Game::~Game()
{
	return;
}


