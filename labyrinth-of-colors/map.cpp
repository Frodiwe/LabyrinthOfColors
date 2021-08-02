//
//  map.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "map.hpp"
#include "cell.hpp"
#include "render_component.h"

Map::Map() :cells{}
{
	
}

void Map::render()
{
	for (const auto& cells_row : cells)
	{
		int x = 0;
		int y = 0;
		
		for (const auto& cell : cells_row)
		{
			cell.render(x, y);
			
			x += cells_row.front().width();
		}
		
		y += cells.front().front().height();
	}
}
