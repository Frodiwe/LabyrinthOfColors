//
//  events_queue.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 3.08.21.
//

#include "events_queue.hpp"

#include <algorithm>

EventsQueue::listeners_map EventsQueue::listeners = {};

void EventsQueue::subscribe(Event event, std::function<void ()> listener)
{
	if (EventsQueue::listeners.count(event) == 0) {
		EventsQueue::listeners[event] = {};
	}
	
	EventsQueue::listeners.at(event).emplace_back(gen_event_id(EventsQueue::listeners.at(event)), listener);
}

void EventsQueue::unsubscribe(Event event, ListenerId event_id)
{
	if (EventsQueue::listeners.count(event) == 0) {
		return;
	}
	
	auto& listeners = EventsQueue::listeners.at(event);
	
	listeners.erase(
		std::remove_if(
			listeners.begin(),
			listeners.end(),
			[&event_id](const auto& l) { return l.first == event_id; }
		),
		listeners.end()
	);
}

void EventsQueue::publish(Event event) { 
	if (EventsQueue::listeners.count(event) == 0) {
		return;
	}
	
	for (const auto& listener : EventsQueue::listeners.at(event)) {
		listener.second();
	}
}

