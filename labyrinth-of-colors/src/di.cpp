//
//  di.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#include "di.hpp"

#include "render/render_list.hpp"
#include "render/render_controller.hpp"

std::optional<std::shared_ptr<RenderList>> DI::render_list = nullptr;
std::optional<std::shared_ptr<RenderController>> DI::render_controller = nullptr;

std::shared_ptr<RenderList> DI::get_render_list()
{
	if (not render_list)
	{
		DI::render_list = std::shared_ptr<RenderList>{new RenderList()};
	}

	return *render_list;
}

std::shared_ptr<RenderController> DI::get_render_controller()
{
	if (not render_controller)
	{
		DI::render_controller = std::shared_ptr<RenderController>{new RenderController(get_render_list())};
	}

	return *render_controller;
}
