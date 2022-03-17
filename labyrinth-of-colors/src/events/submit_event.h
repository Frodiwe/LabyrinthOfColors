//
//  submit_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.02.22.
//

#ifndef submit_event_h
#define submit_event_h

#include "src/events/event.h"

struct SubmitEvent : public Event
{
    std::string get_name() const override
    {
        return "SUBMIT";
    }
};

#endif /* submit_event_h */
