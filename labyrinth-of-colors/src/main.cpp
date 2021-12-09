#include "src/window.hpp"
#include "src/game.hpp"
#include "src/events/event.h"
#include "src/coord.hpp"
#include "src/di.hpp"
#include "src/key_handler.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, Event* e)
{
    os << e->get_name();
    
	return os;
}

int main(int argc, char *argv[])
{
	Coord::start_x = 800;
	Coord::start_y = 600;
	
    auto window = Window{800, 600, new KeyHandler{DI::get_events_queue()}};
	auto game = Game(&window, DI::get_events_queue());
	
	while (not window.is_quited())
	{
		window.process_events();
		game.render(window.get_renderer());
	}
	
	return EXIT_SUCCESS;
}
