//
//  move_in_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef move_in_event_h
#define move_in_event_h

#include "src/events/event.h"

struct MoveInEvent : public Event
{
    entt::entity to_cell;
    
    MoveInEvent(entt::entity to_cell): to_cell{to_cell}
    { }
    
    std::string get_name() const override
    {
        return "MOVE_IN";
    }
};

#endif /* move_in_event_h */
