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

enum class Event
{
	K_LEFT_KEYDOWN,
	K_RIGHT_KEYDOWN,
	K_UP_KEYDOWN,
	K_DOWN_KEYDOWN,
};

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
	
public:
	static void subscribe(Event event, std::function<void()> listener);
	
	static void unsubscribe(Event event, ListenerId event_id);
	
	static void publish(Event event);
};

#endif /* events_queue_hpp */
