//
//  map.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "map.hpp"
#include "cell.hpp"

#include "src/render_component.h"

Map::Map(std::vector<std::vector<Cell>>&& cells, int32_t start_x, int32_t start_y):
	cells{std::move(cells)},
	start_x{start_x},
	start_y{start_y}
{ }

void Map::render()
{
	for (const auto& cells_row : cells)
	{
		int x = start_x;
		int y = start_y;
		
		for (const auto& cell : cells_row)
		{
			cell.render(x, y);
			
			x += cells_row.front().width();
		}
		
		y += cells.front().front().height();
	}
}

Cell& Map::at(size_t i, size_t j)
{
	if (i > cells.size() or j > cells.front().size()) {
		throw;
	}
	
	return cells[i][j];
}
