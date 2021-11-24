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

#include "src/event.h"
#include "src/listener.hpp"

struct MapPosition;

class MovementSystem
{
private:
	entt::registry& registry;
	
	void move(const entt::entity& from, const entt::entity& to);
	
	entt::entity get_cell(MapPosition at) const;
	
public:
    MovementSystem(entt::registry& registry) : registry{registry}
    { }
	
	void move(const entt::entity& entity, MapPosition to);
	
	bool can_move(MapPosition to);
	
	bool is_cell_exists(MapPosition cell) const;
};

#endif /* movement_system_hpp */
