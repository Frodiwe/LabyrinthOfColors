//
//  map_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "map_kit.hpp"

#include <string_view>

#include <SDL2/SDL.h>

#include "src/components/map_position.h"

#include "src/level/cell_kit.hpp"
#include "src/rect.hpp"
#include "src/coord.hpp"

MapKit::MapKit(entt::registry& registry, CellKit* cell_kit):
	cell_kit{cell_kit},
	registry{registry}
{ }

void MapKit::create_map(SDL_Renderer* renderer, const LevelMap& labyrinth, const LevelActions& actions)
{
	const auto width = 100;
	const auto height = 100;
	const auto offset = 1;
	
	constexpr std::string_view texture_path = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/brick-1.png";
	
    auto y = 0;
    
	for (auto i = 0u; i < labyrinth.size(); i++)
	{
		auto x = 0;
		
		for (auto j = 0u; j < labyrinth[i].size(); j++)
		{
			const auto cell = cell_kit->create_cell(renderer, texture_path, {0, 0, 32, 32}, {x, y, width, height}, labyrinth[i][j], get_cell_action(actions, i, j));
			
			registry.emplace<MapPosition>(cell, MapPosition{i, j});
            
            x += width + offset;
		}
		
		y += height + offset;
	}
	
	
	
	return;
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
