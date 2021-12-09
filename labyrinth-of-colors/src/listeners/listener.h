//
//  listener.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 3.12.21.
//

#ifndef listener_h
#define listener_h

class Event;

class Listener
{
public:
    virtual void operator()(Event* event) = 0;
};

#endif /* listener_h */
