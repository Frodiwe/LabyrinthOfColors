//
//  render_list.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#ifndef render_list_hpp
#define render_list_hpp

#include <memory>
#include <vector>

#include "renderable.h"

class Renderable;

class RenderList
{
private:
	std::vector<Renderable*> objs = {};
	
public:
	RenderableId add(Renderable* obj);
	
	const std::vector<Renderable*>& all() const;
	
	Renderable* const get(RenderableId id) const;
	
	Renderable* pop(RenderableId id);
};

#endif /* render_list_hpp */
