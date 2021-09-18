//
//  level.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#include "level.hpp"

#include "src/player.hpp"
#include "src/level/map.hpp"
#include "src/level/map_position_controller.hpp"

Level::Level(Player* player, Map* map, MapPositionController* map_position_controller):
	map{map},
	player{player},
	map_position_controller{std::move(map_position_controller)}
{}

void Level::render()
{
	map->render();
	player->render();
}

RenderableId Level::r_id() const
{
	return 666;
}
