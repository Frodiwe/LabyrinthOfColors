//
//  player_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.11.21.
//

#include "player_kit.hpp"

#include "src/texture.h"

#include "src/components/position.h"
#include "src/components/map_position.h"
#include "src/components/size.h"
#include "src/components/inventory.h"
#include "src/tags/player.h"

entt::entity PlayerKit::create_player(const Position& start_pos, const MapPosition& start_map_pos) const
{
	const auto player = registry.create();
    
    registry.emplace<Player>(player);
	registry.emplace<Position>(player, start_pos.x, start_pos.y);
	registry.emplace<MapPosition>(player, start_map_pos.i, start_map_pos.j);
	registry.emplace<Size>(player, 50ul, 50ul);
	registry.emplace<Texture>(player, Texture( "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/wizard_idle.png", {0, 0, 32, 32}));
    registry.emplace<Inventory>(player);
	
	return player;
}
