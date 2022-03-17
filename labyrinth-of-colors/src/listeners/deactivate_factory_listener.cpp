//
//  deactivate_factory_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "deactivate_factory_listener.hpp"

#include "src/events/move_out_event.h"
#include "src/systems/color_factory_system.hpp"
#include "src/components/map_position.h"

void DeactivateFactoryListener::operator()(Event *event)
{
    MoveOutEvent* e = dynamic_cast<MoveOutEvent*>(event);
    
    if (auto color_factory = color_factory_system->get_factory_at(registry.get<MapPosition>(e->from_cell)); color_factory != entt::null)
    {
        color_factory_system->deactivate(color_factory);
        
        std::cout << "Factory at " << registry.get<MapPosition>(e->from_cell).i << ", " << registry.get<MapPosition>(e->from_cell).j << " deactivated" << std::endl;
    }
}
