//
//  cell.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef cell_hpp
#define cell_hpp

#include <memory>
#include <optional>
#include <functional>

#include "src/rect.hpp"
#include "src/level/cell_color.h"

class RenderComponent;

class Cell
{
private:
	std::unique_ptr<RenderComponent> render_comp;
	
	Rect target_rect;
	
	CellColor _color;
	
	std::function<void()> action;
	
public:
	Cell(std::unique_ptr<RenderComponent> render_comp, Rect target_rect, CellColor color, std::function<void()>);
	
	void render() const;
	
	void perform_action() const;
	
	CellColor color() const;
	
	size_t width() const;
	
	size_t height() const;
	
	int32_t x() const;
	
	int32_t y() const;

};

#endif /* cell_hpp */
