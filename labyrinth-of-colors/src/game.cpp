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
#include "src/level/cell_action.h"
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

LevelConfig Game::get_level_config(size_t i) const
{
	auto labyrinth = LevelMap{};
	auto actions = LevelActions{};
    auto items = LevelItems{};
	auto color_file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_map"};
	auto actions_file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_actions"};
    auto items_file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_items"};
	const auto COLOR_DECODE_MAP = std::map<char16_t, CellColor>{
		{'0', CellColor::WALL},
		{'1', CellColor::YELLOW},
		{'2', CellColor::RED},
	};
	const auto ACTION_DECODE_MAP = std::map<std::string, CellAction>{
		{"start", CellAction::START},
		{"exit", CellAction::EXIT}
	};
    
    for (std::string line; std::getline(items_file, line);)
    {
        std::regex reg{R"((\w+):\s(\d+),(\d+))"};
        std::smatch match;
        
        if (std::regex_search(line, match, reg))
        {
            items.emplace_back(match[1].str(), std::stoul(match[2].str()), std::stoul(match[3].str()));
        }
    }
	
	for (std::string line; std::getline(actions_file, line);)
	{
		std::regex reg{R"((\w+):\s(\d+),(\d+))"};
		std::smatch match;
		
		if (std::regex_search(line, match, reg))
		{
			actions.emplace_back(ACTION_DECODE_MAP.at(match[1].str()), std::stoul(match[2].str()), std::stoul(match[3].str()));
		}
	}
	
	for (std::string line; std::getline(color_file, line);)
	{
		labyrinth.emplace_back();
		
		for (const auto& letter : line)
		{
			labyrinth.back().emplace_back(COLOR_DECODE_MAP.at(letter));
		}
	}
	
	return {labyrinth, actions, items, 1, 1};
}

Game::Game(Window* window, EventsQueue* events_queue)
{
	auto config = get_level_config(0);
	
	DI::get_player_kit()->create_player(Coord::start_x, Coord::start_y);
	DI::get_map_kit()->create_map(config.labyrinth, config.actions);
    
    for (const auto& [item_name, i, j] : config.items)
    {
        DI::get_items_kit()->create_item(item_name, {i, j});
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


