//
//  activate_factory_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "activate_factory_listener.hpp"

#include "src/events/move_in_event.h"
#include "src/systems/blending_system.hpp"
#include "src/components/color_factory.h"

void ActivateFactoryListener::operator()(Event *event)
{
    MoveInEvent* e = dynamic_cast<MoveInEvent*>(event);
    
    if (registry.all_of<ColorFactory>(e->to_cell))
    {
        blending_system->activate();
    }
}
