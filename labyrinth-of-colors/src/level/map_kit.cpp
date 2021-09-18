//
//  map_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "map_kit.hpp"

#include <string_view>

#include <SDL2/SDL.h>

#include "src/level/map.hpp"
#include "src/level/cell_kit.hpp"
#include "src/rect.hpp"

MapKit::MapKit(CellKit* cell_kit):
	cell_kit{cell_kit}
{ }

Map* MapKit::create_map(SDL_Renderer* renderer)
{
	auto x = 0;
	auto y = 0;
	
	const auto width = 100;
	const auto height = 100;
	const auto offset = 1;
	
	constexpr std::string_view texture_path = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/brick-1.png";
	
	auto result = std::vector<std::vector<Cell*>>{};
	
	for (auto i = 0; i < 4; i++)
	{
		result.emplace_back(std::vector<Cell*>{});
		
		y = -height;
		
		for (auto j = 0; j < 4; j++)
		{
			result.back().emplace_back(cell_kit->create_cell(renderer, texture_path, {0, 0, 32, 32}, {x, y += height + offset, width, height}));
		}
		
		x += width + offset;
	}
	
	return new Map{std::move(result)};
}
