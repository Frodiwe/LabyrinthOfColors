#include "window.hpp"
#include "di.hpp"

int main(int argc, char *argv[])
{
	Window window = Window{DI::get_render_controller()};
	
	
	while (not window.is_quited())
	{
		window.process_events();
		window.render();
	}
	
	return EXIT_SUCCESS;
}
