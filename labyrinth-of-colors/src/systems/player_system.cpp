//
//  player_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#include "player_system.hpp"

#include "src/tags/player.h"

entt::entity PlayerSystem::get_player()
{
    return std::get<0>(*registry.view<Player>().each().begin());
}
