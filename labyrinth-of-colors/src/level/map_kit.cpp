//
//  map_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "map_kit.hpp"

#include <string_view>

#include "src/components/map_position.h"

#include "src/level/cell_kit.hpp"
#include "src/rect.hpp"
#include "src/coord.hpp"

MapKit::MapKit(entt::registry& registry, CellKit* cell_kit):
	cell_kit{cell_kit},
	registry{registry}
{ }

void MapKit::create_map(const LevelMap& labyrinth)
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
			const auto cell = cell_kit->create_cell(texture_path, {0, 0, 32, 32}, {x, y, width, height}, labyrinth[i][j]);
			
			registry.emplace<MapPosition>(cell, MapPosition{i, j});
            
            x += width + offset;
		}
		
		y += height + offset;
	}
	
	
	
	return;
}
