//b
//  map_position_controller.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#include "map_position_controller.hpp"

#include "src/entity.h"
#include "src/level/map.hpp"
#include "src/event.h"
#include "src/events_queue.hpp"
#include "src/level/cell.hpp"
#include "src/coord.hpp"

MapPositionController::MapPositionController(Entity* entity, Map* map):
	entity{entity},
	map{map},
	listeners{
		std::make_unique<Listener>(Event::K_UP_KEYDOWN, [this] { move(current_i - 1, current_j); }),
		std::make_unique<Listener>(Event::K_DOWN_KEYDOWN, [this] { move(current_i + 1, current_j); }),
		std::make_unique<Listener>(Event::K_LEFT_KEYDOWN, [this] { move(current_i, current_j - 1); }),
		std::make_unique<Listener>(Event::K_RIGHT_KEYDOWN, [this] { move(current_i, current_j + 1); })
	}
{ }

void MapPositionController::move(size_t to_i, size_t to_j)
{
	if (not can_move(to_i, to_j))
	{
		return;
	}
	
	move(map->at(current_i, current_j), map->at(to_i, to_j));
	
	current_i = to_i;
	current_j = to_j;
}

void MapPositionController::move(const Cell* from, const Cell* to)
{
	Coord::start_x += from->x() - to->x();
	Coord::start_y += from->y() - to->y();
}

bool MapPositionController::can_move(size_t i, size_t j)
{
	return i < map->row_count() and j < map->col_count() and map->at(i, j)->color() != CellColor::WALL;
}
