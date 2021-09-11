//
//  render_controller.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#include "render_controller.hpp"

#include "render_list.hpp"

RenderController::RenderController(std::shared_ptr<RenderList> render_list):
	render_list{render_list}
{}

void RenderController::render_all()
{
	for (const auto& obj : render_list->all())
		obj->render();
}
