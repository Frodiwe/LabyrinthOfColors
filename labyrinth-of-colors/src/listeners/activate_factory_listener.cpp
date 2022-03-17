//
//  activate_factory_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "activate_factory_listener.hpp"

#include "src/events/move_in_event.h"
#include "src/systems/color_factory_system.hpp"

#include "src/components/map_position.h"

void ActivateFactoryListener::operator()(Event *event)
{
    MoveInEvent* e = dynamic_cast<MoveInEvent*>(event);
    
    if (auto color_factory = color_factory_system->get_factory_at(registry.get<MapPosition>(e->to_cell)); color_factory != entt::null)
    {
        color_factory_system->activate(color_factory);
        
        std::cout << "Factory at " << registry.get<MapPosition>(e->to_cell).i << ", " << registry.get<MapPosition>(e->to_cell).j << " activated" << std::endl;
    }
}
