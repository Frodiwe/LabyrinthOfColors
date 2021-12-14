//
//  game.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.11.21.
//

#include "game.hpp"

#include "window.hpp"
#include "di.hpp"

#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <tuple>

#include <SDL2/SDL.h>

#include "src/player_kit.hpp"
#include "src/level/cell_color.h"
#include "src/level/map_kit.hpp"
#include "src/items_kit.hpp"
#include "src/level/level_config.h"
#include "src/coord.hpp"
#include "src/events_queue.hpp"
#include "src/systems/render_system.hpp"
#include "src/components/map_position.h"
#include "src/components/position.h"
#include "src/texture.h"
#include "src/listeners/move_listener.hpp"
#include "src/events/move_event.h"
#include "src/events_queue.hpp"
#include "src/utils/csv.h"
#include "src/utils/key_value_file.h"

LevelConfig Game::get_level_config(size_t i) const
{
    
    auto color_file = CSV{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_map"};
    auto items_file = KeyValueFile{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_items"};
    auto items = LevelItems{};
    
    for (const auto& [item_name, position_str] : items_file.read())
    {
        items.emplace_back(item_name, ITEMS_COLOR_MAP.at(item_name), MapPosition{position_str});
    }
	
	return {color_file.read(COLOR_DECODE_MAP), items, 0, 0};
}

Game::Game(Window* window, EventsQueue* events_queue)
{
	auto config = get_level_config(0);
	
	DI::get_player_kit()->create_player(Coord::start_x, Coord::start_y);
	DI::get_map_kit()->create_map(config.labyrinth);
    
    for (const auto& [item_name, color, pos] : config.items)
    {
        DI::get_items_kit()->create_item(item_name, color, pos);
    }
    
    events_queue->subscribe<MoveEvent>(new MoveListener{DI::get_registry(), DI::get_movement_system(), DI::get_inventory_system(), DI::get_items_system()});
}

void Game::render(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	
    DI::get_render_system()->render_map(renderer);
    DI::get_render_system()->render_player(renderer);
	
	SDL_RenderPresent(renderer);
}

Game::~Game()
{
	return;
}


