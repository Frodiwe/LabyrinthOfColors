//
//  cell.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef cell_hpp
#define cell_hpp

#include <memory>

class RenderComponent;

class Cell
{
public:
	Cell(std::unique_ptr<RenderComponent> render_comp);
	
	void render(const int x, const int y) const;
	
	int width() const;
	
	int height() const;
};

#endif /* cell_hpp */
