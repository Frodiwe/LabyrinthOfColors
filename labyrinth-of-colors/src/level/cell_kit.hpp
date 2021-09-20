//
//  cell_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#ifndef cell_kit_hpp
#define cell_kit_hpp

#include <string_view>

#include "src/level/cell_color.h"

class Cell;
struct Rect;
class SDL_Renderer;

class CellKit
{
public:
	Cell* create_cell(SDL_Renderer*, std::string_view, Rect, Rect, CellColor) const;
};

#endif /* cell_kit_hpp */
