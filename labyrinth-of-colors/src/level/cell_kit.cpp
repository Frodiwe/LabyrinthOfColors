//
//  cell_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "cell_kit.hpp"

#include <SDL2/SDL.h>

#include "src/components/position.h"
#include "src/components/size.h"
#include "src/level/tags/cell.h"

#include "src/texture.h"
#include "src/rect.hpp"

entt::entity CellKit::create_cell(std::string_view texture_path, Rect frame, Rect target_frame, CellColor color) const
{
	const auto cell = registry.create();
	
    registry.emplace<Cell>(cell);
	registry.emplace<Position>(cell, target_frame.x, target_frame.y);
	registry.emplace<Size>(cell, target_frame.w, target_frame.h);
	registry.emplace<CellColor>(cell, color);
    
    if (color != CellColor::WALL)
    {
        registry.emplace<Texture>(cell, Texture(texture_path, frame));
    }
	
	return cell;
}
