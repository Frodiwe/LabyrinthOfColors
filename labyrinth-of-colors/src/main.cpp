#include "window.hpp"
#include "di.hpp"

#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <tuple>

#include "src/player_kit.hpp"
#include "src/player.hpp"
#include "src/level/cell.hpp"
#include "src/level/cell_color.h"
#include "src/level/cell_action.h"
#include "src/level/map_kit.hpp"
#include "src/level/map.hpp"
#include "src/level/map_position_controller.hpp"
#include "src/level/level.hpp"
#include "src/level/level_config.h"
#include "src/render/render_list.hpp"
#include "src/coord.hpp"
#include "src/event.h"

std::ostream& operator<<(std::ostream& os, Event e)
{
	switch(e)
	{
		case Event::K_LEFT_KEYDOWN   : os << "K_LEFT_KEYDOWN";    break;
		case Event::K_RIGHT_KEYDOWN: os << "K_RIGHT_KEYDOWN"; break;
		case Event::K_UP_KEYDOWN : os << "K_UP_KEYDOWN";  break;
		case Event::K_DOWN_KEYDOWN  : os << "K_DOWN_KEYDOWN";   break;
		case Event::START_LEVEL: os << "START_LEVEL"; break;
		case Event::EXIT_LEVEL  : os << "EXIT_LEVEL";   break;
		case Event::GIVE_PAINT: os << "GIVE_PAINT"; break;
		default    : os.setstate(std::ios_base::failbit);
	}
	
	return os;
}

LevelConfig get_level_config(size_t i)
{
	auto labyrinth = LevelMap{};
	auto actions = LevelActions{};
	auto color_file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_map"};
	auto actions_file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_actions"};
	const auto COLOR_DECODE_MAP = std::map<char16_t, CellColor>{
		{'0', CellColor::WALL},
		{'1', CellColor::YELLOW},
		{'2', CellColor::RED},
	};
	const auto ACTION_DECODE_MAP = std::map<std::string, CellAction>{
		{"start", CellAction::START},
		{"red_paint", CellAction::RED_PAINT},
		{"exit", CellAction::EXIT}
	};
	
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
	
	return {labyrinth, actions, 1, 1};
}

int main(int argc, char *argv[])
{
	Window window = Window{DI::get_render_controller(), 800, 600};
	
	Coord::start_x = 800;
	Coord::start_y = 600;
	
	auto config = get_level_config(0);
	auto map = DI::get_map_kit()->create_map(window.get_renderer(), config.labyrinth, config.actions);
	auto player = DI::get_player_kit()->create_player(
		window.get_renderer(),
		Coord::start_x + map.at(config.start_i, config.start_j)->x(),
		Coord::start_y + map.at(config.start_i, config.start_j)->y()
	);
	auto map_controller = new MapPositionController{&player, &map, config.start_i, config.start_j};
	
	DI::get_render_list()->add(&map);
	DI::get_render_list()->add(&player);
	
	while (not window.is_quited())
	{
		window.process_events();
		window.render();
	}
	
	return EXIT_SUCCESS;
}
