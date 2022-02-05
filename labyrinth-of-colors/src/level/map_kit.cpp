//
//  map_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "map_kit.hpp"

#include <string_view>

#include "src/level/components/exit.h"
#include "src/level/tags/unavailable.h"

#include "src/components/map_position.h"
#include "src/level/cell_kit.hpp"
#include "src/rect.hpp"
#include "src/coord.hpp"
#include "src/consts.h"

MapKit::MapKit(entt::registry& registry, CellKit* cell_kit):
	cell_kit{cell_kit},
	registry{registry}
{ }

void MapKit::create_map(const LevelMap& labyrinth, const MapPosition& exit)
{
	const auto width = 50;
	const auto height = 50;
	const auto offset = 0;
	
    auto y = 0;
    
	for (auto i = 0u; i < labyrinth.size(); i++)
	{
		auto x = 0;
		
		for (auto j = 0u; j < labyrinth[i].size(); j++)
		{
			const auto cell = cell_kit->create_cell(CELL_TEXTURES_MAP.at(labyrinth[i][j]), {0, 0, 32, 32}, {x, y, width, height}, labyrinth[i][j]);
            auto map_pos = MapPosition{i, j};
            
			registry.emplace<MapPosition>(cell, map_pos);
            registry.emplace<Unavailable>(cell);
            
            if (map_pos == exit)
            {
                registry.emplace<Exit>(cell, Texture{EXIT_TEXTURE_PATH, {0, 0, 32, 32}});
            }
            
            x += width + offset;
		}
		
		y += height + offset;
	}
	
	return;
}
