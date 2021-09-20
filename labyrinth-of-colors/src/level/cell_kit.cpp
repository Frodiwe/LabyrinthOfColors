//
//  cell_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "cell_kit.hpp"

#include <SDL2/SDL.h>

#include "src/level/cell.hpp"
#include "src/texture.h"
#include "src/render_component.h"
#include "src/rect.hpp"

Cell* CellKit::create_cell(SDL_Renderer* renderer, std::string_view texture_path, Rect frame, Rect target_frame, CellColor color) const
{
	return new Cell{
		std::unique_ptr<RenderComponent>{new Texture(renderer, texture_path, frame)},
		target_frame,
		color
	};
}
