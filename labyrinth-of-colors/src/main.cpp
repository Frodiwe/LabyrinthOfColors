#include "window.hpp"
#include "di.hpp"

#include "src/level/level_kit.hpp"
#include "src/level/level.hpp"
#include "src/render/render_list.hpp"

int main(int argc, char *argv[])
{
	Window window = Window{DI::get_render_controller()};
	
	auto level = DI::get_level_kit()->create_level(window.get_renderer());
	DI::get_render_list()->add(&level);
	
	while (not window.is_quited())
	{
		window.process_events();
		window.render();
	}
	
	return EXIT_SUCCESS;
}
