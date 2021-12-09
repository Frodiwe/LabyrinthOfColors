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

void MovementSystem::move(const entt::entity& player, const entt::entity& from, const entt::entity& to)
{	
    move_world_coords(from, to);
	
    registry.get<MapPosition>(player) = registry.get<MapPosition>(to);
    
    for (const auto [ent, tex, pos, m] : DI::get_registry().view<Player, Texture, Position, MapPosition>().each())
    {
        std::cout << pos.x << ", " << pos.y << " –> " << m.i << ", " << m.j << std::endl;
    }
}

bool MovementSystem::can_move(const entt::entity& cell)
{
	return registry.get<CellColor>(cell) != CellColor::WALL;
}

void MovementSystem::move_world_coords(const entt::entity &from, const entt::entity &to)
{
	Coord::start_x += registry.get<Position>(from).x - registry.get<Position>(to).x;
	Coord::start_y += registry.get<Position>(from).y - registry.get<Position>(to).y;
}




