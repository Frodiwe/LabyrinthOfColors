//
//  window.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "window.hpp"
#include "key_handler.hpp"

Window::Window(int32_t width, int32_t height, KeyHandler* kh) :
	key_handler{kh},
	event{new SDL_Event{}},
	WIDTH{width},
	HEIGHT{height}
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	if (not init_window())
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		
		return;
	}
	
	
	if (not init_renderer(window_handler))
	{
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		
		return;
	}
	
	if (not init_image_loading())
	{
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
		
		return;
	}
	
	is_inited = true;
}

bool Window::init_window()
{
	window_handler = SDL_CreateWindow("Labyrinth Of Colors", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	
	return window_handler != nullptr;
}

bool Window::init_renderer(SDL_Window* window)
{
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	if (renderer == nullptr) {
		return false;
	}
	
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
	
	return true;
}

bool Window::init_image_loading()
{
	const auto flags = IMG_INIT_PNG;
	
	return IMG_Init(flags) & flags;
}

void Window::process_events()
{
	while (SDL_PollEvent(event) != 0)
	{
		switch(event->type)
		{
			case SDL_QUIT:
				_is_quited = true;
				break;
				
			case SDL_KEYDOWN:
				key_handler->process(event->key);
		}
	}
}

bool Window::is_quited() const
{
	return _is_quited;
}

SDL_Renderer* Window::get_renderer() const
{
	return renderer;
}

Window::~Window()
{
	SDL_DestroyWindow(window_handler);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	IMG_Quit();
}
