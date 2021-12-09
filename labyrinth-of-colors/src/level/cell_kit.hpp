//
//  cell_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#ifndef cell_kit_hpp
#define cell_kit_hpp

#include <string_view>

#include "third_party/entt/entity/registry.hpp"

#include "src/level/cell_color.h"
#include "src/level/cell_action.h"

class Cell;
struct Rect;
class SDL_Renderer;

class CellKit
{
private:
	entt::registry& registry;
	
public:
	CellKit(entt::registry& registry) : registry{registry}
	{ }
	
	entt::entity create_cell(std::string_view, Rect, Rect, CellColor, CellAction) const;
};

#endif /* cell_kit_hpp */
