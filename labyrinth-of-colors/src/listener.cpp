//
//  listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#include "listener.hpp"

#include "events_queue.hpp"
#include "event.h"

Listener::Listener(Event event, std::function<void()> listener)
	: event{event}, listener_id{EventsQueue::subscribe(event, listener)}
{ }

Listener::~Listener()
{
	EventsQueue::unsubscribe(event, listener_id);
}
