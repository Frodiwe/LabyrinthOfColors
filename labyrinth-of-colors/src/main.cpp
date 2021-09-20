#include "window.hpp"
#include "di.hpp"

#include <vector>
#include <fstream>
#include <string>

#include "src/level/level_kit.hpp"
#include "src/level/level.hpp"
#include "src/level/level_config.h"
#include "src/level/cell_color.h"
#include "src/render/render_list.hpp"
#include "src/coord.hpp"

LevelConfig get_level_config(size_t i)
{
	auto labyrinth = std::vector<std::vector<CellColor>>{};
	auto file = std::ifstream{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/level_" + std::to_string(i)};
	
	for (std::string line; std::getline(file, line);)
	{
		labyrinth.emplace_back();
		
		for (const auto& letter : line)
		{
			switch (letter)
			{
				case '0':
					labyrinth.back().emplace_back(CellColor::YELLOW);
					
					break;
					
				case 'w':
				default:
					labyrinth.back().emplace_back(CellColor::WALL);
					
					break;
			}
		}
	}
	
	return {labyrinth};
}

int main(int argc, char *argv[])
{
	Window window = Window{DI::get_render_controller(), 800, 600};
	
	Coord::start_x = 800;
	Coord::start_y = 600;
	
	auto level = DI::get_level_kit()->create_level(window.get_renderer(), get_level_config(0));
	
	DI::get_render_list()->add(&level);
	
	while (not window.is_quited())
	{
		window.process_events();
		window.render();
	}
	
	return EXIT_SUCCESS;
}
