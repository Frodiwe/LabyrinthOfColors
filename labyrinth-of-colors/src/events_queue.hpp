//
//  events_queue.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 3.08.21.
//

#ifndef events_queue_hpp
#define events_queue_hpp

#include <functional>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include "events_queue.hpp"
#include "event.h"

enum class Event;

using ListenerId = int32_t;

class EventsQueue
{
	template<typename... Args>
	using listeners_map = std::map<
		Event,
		std::vector< std::pair<ListenerId, std::function<void(Args...)>> >
	>;
	
private:
	template <class... Args>
	static listeners_map<Args...> listeners;
	
	template<typename T>
	static ListenerId gen_event_id(const T& listeners)
	{
		return listeners.empty() ? 0 : listeners.back().first + 1;
	};
	
	template<typename... Args>
	static ListenerId add_listener(Event event, ListenerId id, std::function<void(Args...)> listener)
	{
		EventsQueue::listeners<Args...>.at(event).emplace_back(id, listener);
		
		return id;
	}
	
public:
	template<typename... Args>
	static ListenerId subscribe(Event event, std::function<void(Args...)> listener)
	{
		if (EventsQueue::listeners<Args...>.count(event) == 0) {
			EventsQueue::listeners<Args...>[event] = {};
		}
		
		return add_listener(event, gen_event_id(EventsQueue::listeners<Args...>.at(event)), listener);
	}
	
	template<typename... Args>
	static void unsubscribe(Event event, ListenerId event_id)
	{
		if (EventsQueue::listeners<Args...>.count(event) == 0) {
			return;
		}
		
		auto& listeners = EventsQueue::listeners<Args...>.at(event);
		
		listeners.erase(
			std::remove_if(
				listeners.begin(),
				listeners.end(),
				[&event_id](const auto& l) { return l.first == event_id; }
			),
			listeners.end()
		);
	}
	
	template<typename... Args>
	static void publish(Event event, Args... args)
	{
		std::cout << "Event " << event << " published" << std::endl;
		 
		if (EventsQueue::listeners<Args...>.count(event) == 0)
		{
			return;
		}

		for (const auto& listener : EventsQueue::listeners<Args...>.at(event))
		{
			listener.second(std::forward<Args>(args)...);
		}
	}
};

template<typename... Args>
EventsQueue::listeners_map<Args...> EventsQueue::listeners = {};

#endif /* events_queue_hpp */
