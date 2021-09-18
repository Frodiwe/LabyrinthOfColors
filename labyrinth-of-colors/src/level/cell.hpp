//
//  cell.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef cell_hpp
#define cell_hpp

#include <memory>

#include "src/rect.hpp"

class RenderComponent;

class Cell
{
private:
	std::unique_ptr<RenderComponent> render_comp;
	
	Rect target_rect;
	
public:
	Cell(std::unique_ptr<RenderComponent> render_comp, Rect target_rect);
	
	Cell(Cell&&) noexcept;
	
	void render() const;
	
	size_t width() const;
	
	size_t height() const;
	
	int32_t x() const;
	
	int32_t y() const;

};

#endif /* cell_hpp */
