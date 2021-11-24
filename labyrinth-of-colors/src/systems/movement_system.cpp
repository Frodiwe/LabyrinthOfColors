//
//  movement_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 15.11.21.
//

#include "movement_system.hpp"

#include "src/components/map_position.h"
#include "src/level/components/action.h"
#include "src/components/position.h"
#include "src/level/cell_color.h"
#include "src/level/tags/cell.h"
#include "src/tags/player.h"
#include "src/components/position.h"
#include "src/components/map_position.h"
#include "src/texture.h"
#include "src/di.hpp"

#include "src/coord.hpp"

#include <iostream>

bool MovementSystem::is_cell_exists(MapPosition at) const
{
	try {
		get_cell(at);
		
		return true;
	}
	catch(std::logic_error e) {
		return false;
	}
}

void MovementSystem::move(const entt::entity& player, MapPosition to)
{
	if (not is_cell_exists(to) or not can_move(to))
	{
		return;
	}
	
	move(get_cell(registry.get<MapPosition>(player)), get_cell(to));
	
//	registry.get<Action>(get_cell(to))();
    registry.get<MapPosition>(player) = to;
    
    for (const auto [ent, tex, pos, m] : DI::get_registry().view<Player, Texture, Position, MapPosition>().each())
    {
        std::cout << pos.x << ", " << pos.y << " –> " << m.i << ", " << m.j << std::endl;
    }
}

bool MovementSystem::can_move(MapPosition to)
{
	return registry.get<CellColor>(get_cell(to)) != CellColor::WALL;
}

entt::entity MovementSystem::get_cell(MapPosition at) const
{
    for (const auto [ent, tex, pos, m] : DI::get_registry().view<Cell, Texture, Position, MapPosition>().each())
    {
        std::cout << pos.x << ", " << pos.y << " –> " << m.i << ", " << m.j << std::endl;
    }
    
	for (const auto [entity, map_position] : registry.view<Cell, MapPosition>().each())
	{
		if (map_position.i == at.i and map_position.j == at.j) {
			return entity;
		}
	}
	
	throw std::logic_error{""};
}

void MovementSystem::move(const entt::entity &from, const entt::entity &to)
{
	Coord::start_x += registry.get<Position>(from).x - registry.get<Position>(to).x;
	Coord::start_y += registry.get<Position>(from).y - registry.get<Position>(to).y;
}




