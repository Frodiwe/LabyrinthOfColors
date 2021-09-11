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

enum class Event;

using ListenerId = int32_t;

class EventsQueue
{
	using listeners_map = std::map<
	Event,
		std::vector< std::pair<ListenerId, std::function<void()>> >
	>;
	
private:
	static listeners_map listeners;
	
	template<typename T>
	static ListenerId gen_event_id(const T& listeners)
	{
		return listeners.empty() ? 0 : listeners.back().first + 1;
	};
	
	static ListenerId add_listener(Event event, ListenerId id, std::function<void()> listener)
	{
		EventsQueue::listeners.at(event).emplace_back(id, listener);
		
		return id;
	}
	
public:
	static ListenerId subscribe(Event event, std::function<void()> listener);
	
	static void unsubscribe(Event event, ListenerId event_id);
	
	static void publish(Event event);
};

#endif /* events_queue_hpp */
