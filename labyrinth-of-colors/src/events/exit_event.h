//
//  exit_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 14.12.21.
//

#ifndef exit_event_h
#define exit_event_h

#include "src/events/event.h"

struct ExitEvent : public Event
{
    ExitEvent() = default;
    
    std::string get_name() const override
    {
        return "EXIT";
    }
};

#endif /* exit_event_h */
