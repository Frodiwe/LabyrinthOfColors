//
//  player_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.11.21.
//

#ifndef player_kit_hpp
#define player_kit_hpp

#include "stdlib.h"

#include "third_party/entt/entity/registry.hpp"

class SDL_Renderer;

class PlayerKit
{
private:
	entt::registry& registry;
	
public:
	PlayerKit(entt::registry& registry) : registry{registry}
	{ };
	
	entt::entity create_player(SDL_Renderer* renderer, int32_t start_x, int32_t start_y) const;
};

#endif /* player_kit_hpp */
