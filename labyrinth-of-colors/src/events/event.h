//
//  event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#ifndef event_h
#define event_h

#include <iostream>
#include <string>

struct Event
{
    virtual std::string get_name() const = 0;
};

std::ostream& operator<<(std::ostream& os, Event* e);

#endif /* event_h */
