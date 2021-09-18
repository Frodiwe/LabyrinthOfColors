//
//  render_list.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#include <exception>
#include <string>

#include "render_list.hpp"

#include "renderable.h"

RenderableId RenderList::add(Renderable* obj)
{
	objs.emplace_back(obj);
	
	return obj->r_id();
}

const std::vector<Renderable*>& RenderList::all() const
{
	return objs;
}

Renderable* const RenderList::get(RenderableId id) const
{
	for (const auto& obj : objs)
		if (obj->r_id() == id)
			return obj;
	
	throw std::logic_error{"Renderable object with id " + std::to_string(id) + " was not found"};
}

Renderable* RenderList::pop(RenderableId id)
{
	auto it = std::find_if(objs.begin(), objs.end(), [&id](const auto& obj) { return obj->r_id() == id; });
	auto removed = std::move(*it);
	
	objs.erase(it, it + 1);
	
	return removed;
}
