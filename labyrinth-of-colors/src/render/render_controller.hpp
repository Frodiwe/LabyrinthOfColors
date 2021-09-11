//
//  render_controller.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#ifndef render_controller_hpp
#define render_controller_hpp

#include <memory>

class RenderList;

class RenderController
{
private:
	std::shared_ptr<RenderList> render_list;
public:
	RenderController(std::shared_ptr<RenderList> render_list);
	
	void render_all();
};

#endif /* render_controller_hpp */
