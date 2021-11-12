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

Map MapKit::create_map(SDL_Renderer* renderer, const LevelMap& labyrinth, const LevelActions& actions)
{
	auto x = 0;
	auto y = 0;
	
	const auto width = 100;
	const auto height = 100;
	const auto offset = 1;
	
	constexpr std::string_view texture_path = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/brick-1.png";

	auto result = std::vector<std::vector<Cell*>>{};
	
	for (const auto& row : labyrinth)
	{
		result.emplace_back(std::vector<Cell*>{});
		
		x = -width;
		
		for (const auto& color : row)
		{
			result.back().emplace_back(cell_kit->create_cell(renderer, texture_path, {0, 0, 32, 32}, {x += width + offset, y, width, height}, color, get_cell_action(actions, result.size() - 1, result.back().size())));
		}
		
		y += height + offset;
	}
	
	return Map{std::move(result)};
}

CellAction MapKit::get_cell_action(LevelActions actions, size_t i, size_t j) const
{
	auto result = std::find_if(actions.begin(), actions.end(), [&i, &j](const auto& action) {
		return std::get<1>(action) == i and std::get<2>(action) == j;
	});
	
	if (result == actions.end()) {
		return CellAction::NONE;
	}
	
	return std::get<0>(*result);
}
