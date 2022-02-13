//
//  handle_exit_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef handle_exit_listener_hpp
#define handle_exit_listener_hpp

#include "src/listeners/listener.h"
#include "src/events_queue.hpp"

#include "third_party/entt/entity/registry.hpp"

class HandleExitListener : public Listener
{
    entt::registry& registry;
    
    EventsQueue* events_queue;
    
public:
    HandleExitListener(entt::registry& registry, EventsQueue* events_queue) : registry{registry}, events_queue{events_queue}
    { }
    
    void operator()(Event* event);
};


#endif /* handle_exit_listener_hpp */
