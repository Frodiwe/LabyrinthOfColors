#include "src/window.hpp"
#include "src/game.hpp"
#include "src/event.h"
#include "src/coord.hpp"
#include "src/di.hpp"

#include <iostream>
#include "src/components/position.h"
#include "src/components/map_position.h"
#include "src/level/tags/cell.h"
#include "src/texture.h"

std::ostream& operator<<(std::ostream& os, Event e)
{
	switch(e)
	{
		case Event::K_LEFT_KEYDOWN   : os << "K_LEFT_KEYDOWN";    break;
		case Event::K_RIGHT_KEYDOWN: os << "K_RIGHT_KEYDOWN"; break;
		case Event::K_UP_KEYDOWN : os << "K_UP_KEYDOWN";  break;
		case Event::K_DOWN_KEYDOWN  : os << "K_DOWN_KEYDOWN";   break;
		case Event::START_LEVEL: os << "START_LEVEL"; break;
		case Event::EXIT_LEVEL  : os << "EXIT_LEVEL";   break;
		case Event::GIVE_PAINT: os << "GIVE_PAINT"; break;
		default    : os.setstate(std::ios_base::failbit);
	}
	
	return os;
}

int main(int argc, char *argv[])
{
	Coord::start_x = 800;
	Coord::start_y = 600;
	
	auto window = Window{800, 600};
	auto game = Game(&window);
    
    std::cout << DI::get_registry().size() << std::endl;
    
    for (const auto [ent, tex, pos, m] : DI::get_registry().view<Cell, Texture, Position, MapPosition>().each())
    {
        std::cout << pos.x << ", " << pos.y << " –> " << m.i << ", " << m.j << std::endl;
    }
	
	while (not window.is_quited())
	{
		window.process_events();
		game.render(window.get_renderer());
	}
	
	return EXIT_SUCCESS;
}
