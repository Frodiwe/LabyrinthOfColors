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
#include "src/tags/player.h"

entt::entity PlayerKit::create_player(SDL_Renderer* renderer, int32_t start_x, int32_t start_y) const
{
	const auto player = registry.create();
    
    registry.emplace<Player>(player);
	registry.emplace<Position>(player, start_x, start_y);
	registry.emplace<MapPosition>(player, 0ul, 0ul);
	registry.emplace<Size>(player, 100ul, 100ul);
	registry.emplace<Texture>(player, Texture(renderer, "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/wizard-idle.png", {0, 0, 32, 32}));
	
	return player;
}
