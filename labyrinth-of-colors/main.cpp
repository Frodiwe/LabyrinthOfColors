#include <iostream>
#include "window.hpp"

int main(int argc, char *argv[])
{
	Window window = Window{};
	
	while (not window.is_quited())
	{
		window.process_events();
		window.render();
	}
	
	return EXIT_SUCCESS;
}
