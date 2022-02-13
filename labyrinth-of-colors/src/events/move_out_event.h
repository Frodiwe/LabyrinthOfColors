//
//  move_out_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef move_out_event_h
#define move_out_event_h

#include "src/events/event.h"

struct MoveOutEvent : public Event
{
    entt::entity from_cell;
    
    MoveOutEvent(entt::entity from_cell): from_cell{from_cell}
    { }
    
    std::string get_name() const override
    {
        return "MOVE_OUT";
    }
};

#endif /* move_out_event_h */
