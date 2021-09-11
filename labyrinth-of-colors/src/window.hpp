//
//  window.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef window_hpp
#define window_hpp

#include <memory>

const int WIDTH = 800;
const int HEIGHT = 600;

class SDL_Window;
class SDL_Renderer;
class KeyHandler;
class RenderController;

union SDL_Event;

class Window
{
private:
	SDL_Window* window_handler = nullptr;
	
	SDL_Renderer* renderer = nullptr;
	
	SDL_Event* event = nullptr;
	
	KeyHandler* key_handler = nullptr;
	
	std::shared_ptr<RenderController> render_controller;
	
	bool _is_quited = false;
	
	bool is_inited = false;
	
	bool init_window();

	bool init_renderer(SDL_Window* window);

	bool init_image_loading();
	
public:
	Window(std::shared_ptr<RenderController> render_controller);
	
	void render();
	
	void process_events();
	
	bool is_quited() const;
	
	~Window();
};

#endif /* window_hpp */
