//
//  window.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef window_hpp
#define window_hpp

#include <memory>

class SDL_Window;
class SDL_Renderer;
class KeyHandler;
class RenderController;

union SDL_Event;

class Window
{
private:
	int32_t WIDTH = 800;
	
	int32_t HEIGHT = 600;
	
	SDL_Window* window_handler = nullptr;
	
	SDL_Renderer* renderer = nullptr;
	
	SDL_Event* event = nullptr;
	
	KeyHandler* key_handler = nullptr;
	
	bool _is_quited = false;
	
	bool is_inited = false;
	
	bool init_window();

	bool init_renderer(SDL_Window* window);

	bool init_image_loading();
	
public:
	Window(int32_t, int32_t, KeyHandler*);
	
	void process_events();
	
	bool is_quited() const;
	
	SDL_Renderer* get_renderer() const;
	
	~Window();
};

#endif /* window_hpp */
