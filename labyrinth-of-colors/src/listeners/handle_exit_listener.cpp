//
//  handle_exit_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "handle_exit_listener.hpp"

#include "src/events/move_in_event.h"
#include "src/events/exit_event.h"

#include "src/level/components/exit.h"

void HandleExitListener::operator()(Event* event)
{
    MoveInEvent* e = dynamic_cast<MoveInEvent*>(event);
    
    if (not registry.all_of<Exit>(e->to_cell))
    {
        return;
    }
    
    events_queue->publish<ExitEvent>();
}
