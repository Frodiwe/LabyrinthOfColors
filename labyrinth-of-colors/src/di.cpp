//
//  di.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#include "di.hpp"

#include "src/render/render_list.hpp"
#include "src/render/render_controller.hpp"
#include "src/level/cell_kit.hpp"
#include "src/level/map_kit.hpp"
#include "src/level/level_kit.hpp"

std::shared_ptr<RenderList> DI::render_list = std::shared_ptr<RenderList>{new RenderList()};
std::shared_ptr<RenderController> DI::render_controller = std::shared_ptr<RenderController>{new RenderController(DI::render_list)};
CellKit* DI::cell_kit = new CellKit();
MapKit* DI::map_kit = new MapKit(DI::cell_kit);
LevelKit* DI::level_kit = new LevelKit(DI::map_kit);

std::shared_ptr<RenderList> DI::get_render_list()
{
	return render_list;
}

std::shared_ptr<RenderController> DI::get_render_controller()
{
	return render_controller;
}

LevelKit* DI::get_level_kit()
{
	return level_kit;
}
