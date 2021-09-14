//
//  level.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#include "level.hpp"

#include "src/entity.h"
#include "src/level/map.hpp"
#include "src/level/map_position_controller.hpp"

Level::Level(
			 std::shared_ptr<Entity> player,
			 std::shared_ptr<Map> map,
			 std::unique_ptr<MapPositionController> map_position_controller
			):
	map{map},
	player{player},
	map_position_controller{std::move(map_position_controller)}
{}

void Level::render()
{
	
}
