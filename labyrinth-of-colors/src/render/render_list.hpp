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
	std::vector<std::unique_ptr<Renderable>> objs = {};
	
public:
	RenderableId add(std::unique_ptr<Renderable>&& obj);
	
	const std::vector<std::unique_ptr<Renderable>>& all() const;
	
	const std::unique_ptr<Renderable>& get(RenderableId id) const;
	
	std::unique_ptr<Renderable> pop(RenderableId id);
};

#endif /* render_list_hpp */
