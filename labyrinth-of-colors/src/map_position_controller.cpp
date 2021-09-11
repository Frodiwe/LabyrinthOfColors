//
//  map_position_controller.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#include "map_position_controller.hpp"

#include "entity.h"
#include "map.hpp"
#include "event.h"
#include "events_queue.hpp"
#include "cell.hpp"
#include "listener.hpp"

MapPositionController::MapPositionController(std::unique_ptr<Entity> entity, std::unique_ptr<Map> map)
	:	entity{std::move(entity)},
		map{std::move(map)},
		listeners{
			std::make_unique<Listener>(Event::K_UP_KEYDOWN, [this] { move(i + 1, j); }),
			std::make_unique<Listener>(Event::K_DOWN_KEYDOWN, [this] { move(i - 1, j); }),
			std::make_unique<Listener>(Event::K_LEFT_KEYDOWN, [this] { move(i, j - 1); }),
			std::make_unique<Listener>(Event::K_RIGHT_KEYDOWN, [this] { move(i, j + 1); })
		}
{ }

void MapPositionController::move(size_t to_i, size_t to_j)
{
	i = to_i;
	j = to_j;
	
	move_to_cell(map->at(i, j));
}

void MapPositionController::move_to_cell(const Cell& cell)
{
	entity->move(cell.x() + cell.width() / 2, cell.y() + cell.height() / 2);
}
