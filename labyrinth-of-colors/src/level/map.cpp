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

size_t Map::col_count() const
{
	return cells.front().size();
}

size_t Map::row_count() const
{
	return cells.size();
}

Cell* Map::at(size_t i, size_t j)
{
	if (i > cells.size() or j > cells.front().size()) {
		throw;
	}
	
	return cells[i][j];
}
