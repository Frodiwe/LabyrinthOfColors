//
//  player_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#ifndef player_system_hpp
#define player_system_hpp

#include "third_party/entt/entity/registry.hpp"

class PlayerSystem
{
private:
    entt::registry& registry;
    
public:
    PlayerSystem(entt::registry& r) : registry{r}
    { }
    
    entt::entity get_player();
};

#endif /* player_system_hpp */
