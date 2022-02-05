//
//  movement_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 15.11.21.
//

#ifndef movement_system_hpp
#define movement_system_hpp

#include <memory>
#include <array>

#include "third_party/entt/entity/registry.hpp"

#include "src/events/event.h"

struct MapPosition;

class MovementSystem
{
private:
	entt::registry& registry;
	
public:
    MovementSystem(entt::registry& registry) : registry{registry}
    { }
	
    void move(const entt::entity& entity, const entt::entity& from, const entt::entity& to);
    
    void move_world_coords(const entt::entity& from, const entt::entity& to);
	
	bool can_move(const entt::entity& cell);
};

#endif /* movement_system_hpp */
