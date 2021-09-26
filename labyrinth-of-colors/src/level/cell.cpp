//
//  cell.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "cell.hpp"

#include <SDL2/SDL.h>

#include "src/render_component.h"
#include "src/rect.hpp"
#include "src/coord.hpp"

Cell::Cell(std::unique_ptr<RenderComponent> render_comp, Rect target_rect, CellColor color, std::function<void()> action):
	render_comp{std::move(render_comp)},
	target_rect{target_rect},
	_color{color},
	action{action}
{ }

size_t Cell::width() const
{
	return target_rect.w;
}

size_t Cell::height() const
{
	return target_rect.h;
}

int32_t Cell::x() const
{
	return target_rect.x;
}

int32_t Cell::y() const
{
	return target_rect.y;
}

void Cell::render() const
{
	if (_color == CellColor::WALL) {
		return;
	}
	
	render_comp->render({
		Coord::start_x + target_rect.x,
		Coord::start_y + target_rect.y,
		target_rect.w,
		target_rect.h
	});
}

void Cell::perform_action() const
{
	if (not action)
		return;
	
	action();
}

CellColor Cell::color() const
{
	return _color;
}
