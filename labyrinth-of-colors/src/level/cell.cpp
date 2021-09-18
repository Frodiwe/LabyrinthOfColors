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

Cell::Cell(std::unique_ptr<RenderComponent> render_comp, Rect target_rect):
	render_comp{std::move(render_comp)},
	target_rect{target_rect}
{ }

Cell::Cell(Cell&& rhs) noexcept:
	render_comp{std::move(rhs.render_comp)},
	target_rect{std::move(rhs.target_rect)}
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
	render_comp->render(target_rect);
}
