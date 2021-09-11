//
//  di.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#ifndef di_hpp
#define di_hpp

#include <memory>
#include <optional>

class RenderList;
class RenderController;

class DI
{
private:
	static std::optional<std::shared_ptr<RenderList>> render_list;
	
	static std::optional<std::shared_ptr<RenderController>> render_controller;
	
public:
	static std::shared_ptr<RenderList> get_render_list();
	
	static std::shared_ptr<RenderController> get_render_controller();
};

#endif /* di_hpp */
