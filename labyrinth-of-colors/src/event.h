//
//  event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#ifndef event_h
#define event_h

#include <iostream>

enum class Event
{
	K_LEFT_KEYDOWN,
	K_RIGHT_KEYDOWN,
	K_UP_KEYDOWN,
	K_DOWN_KEYDOWN,
	
	START_LEVEL,
	EXIT_LEVEL,
	GIVE_PAINT,
};

std::ostream& operator<<(std::ostream& os, Event e);

#endif /* event_h */
