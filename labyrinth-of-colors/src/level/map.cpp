//
//  map.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "map.hpp"

#include "cell.hpp"
#include "src/render_component.h"

Map::Map(std::vector<std::vector<Cell*>>&& cells):
	cells{std::move(cells)}
{ }

void Map::render()
{
	for (const auto& cells_row : cells)
	{
		for (const auto& cell : cells_row)
		{
			cell->render();
		}
	}
}

Cell* Map::at(size_t i, size_t j)
{
	if (i > cells.size() or j > cells.front().size()) {
		throw;
	}
	
	return cells[i][j];
}
