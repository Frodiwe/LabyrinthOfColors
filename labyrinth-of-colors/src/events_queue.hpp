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
#include <typeindex>

#include "events_queue.hpp"
#include "event.h"
#include "src/listeners/listener.h"

using ListenerId = int32_t;

class EventsQueue
{
    using Listeners = std::vector<std::pair<ListenerId, Listener*>>;
	using ListenersMap = std::map<std::type_index, Listeners>;
	
private:
    ListenersMap listeners = {};
	
	ListenerId gen_event_id(const Listeners& listeners)
	{
		return listeners.empty() ? 0 : listeners.back().first + 1;
	};
	
    template<typename EventT>
	ListenerId add_listener(ListenerId id, Listener* listener)
	{
		EventsQueue::listeners.at(typeid(EventT)).emplace_back(id, listener);
		
		return id;
	}
	
public:
    template<typename EventT>
	ListenerId subscribe(Listener* listener)
	{
		if (EventsQueue::listeners.count(typeid(EventT)) == 0) {
			EventsQueue::listeners[typeid(EventT)] = {};
		}
		
		return add_listener<EventT>(gen_event_id(EventsQueue::listeners.at(typeid(EventT))), listener);
	}
	
    template<typename EventT>
    void unsubscribe(ListenerId listener_id)
	{
		if (EventsQueue::listeners.count(typeid(EventT)) == 0) {
			return;
		}
		
		auto& listeners = EventsQueue::listeners.at(typeid(EventT));
		
		listeners.erase(
			std::remove_if(
				listeners.begin(),
				listeners.end(),
				[&listener_id](const auto& l) { return l.first == listener_id; }
			),
			listeners.end()
		);
	}
	
    template<typename EventT, typename... Args>
	void publish(Args&&... args)
	{
        auto event = new EventT{std::forward<Args>(args)...};
        
		std::cout << "Event " << event << " published" << std::endl;
		 
		if (EventsQueue::listeners.count(typeid(EventT)) == 0)
		{
			return;
		}

		for (const auto& listener : EventsQueue::listeners.at(typeid(EventT)))
		{
            (*listener.second)(event);
		}
	}
};

#endif /* events_queue_hpp */
