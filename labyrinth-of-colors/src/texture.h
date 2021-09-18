//
//  texture.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.07.21.
//

#ifndef texture_h
#define texture_h

#include <string_view>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "src/render_component.h"
#include "src/rect.hpp"

class Texture : public RenderComponent
{
public:
	Texture(SDL_Renderer* renderer, std::string_view path, Rect frame)
		: texture{this->load_texture(renderer, path)},
		  renderer{renderer},
		  frame{frame.x, frame.y, frame.w, frame.h}
	{ }
	
	~Texture()
	{
		SDL_DestroyTexture(this->texture);
	}
	
	bool is_loaded()
	{
		return this->texture != nullptr;
	}
	
	void set_frame(const int x, const int y, const int w, const int h)
	{
		this->frame = SDL_Rect{x, y, w, h};
	}
	
	void render(const Rect& target_rect)
	{
		SDL_RenderCopy(this->renderer, this->texture, &this->frame, new SDL_Rect{target_rect.x, target_rect.y, target_rect.w, target_rect.h});
	}
	
protected:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect frame;
	
	SDL_Texture* load_texture(SDL_Renderer* renderer, std::string_view path)
	{
		SDL_Texture* texture = nullptr;
		SDL_Surface* texture_surface = IMG_Load(path.data());
		
		if (texture_surface == nullptr)
		{
			std::cout << "Unable to load image " << path << "! SDL_Image error: " << IMG_GetError() << std::endl;
			
			return nullptr;
		}

		texture = SDL_CreateTextureFromSurface(renderer, texture_surface);
		
		if (texture == nullptr)
		{
			std::cout << "Unable to create texture from " << path << "! SDL_Image error: " << SDL_GetError() << std::endl;
		}

		SDL_FreeSurface(texture_surface);

		return texture;
	}
};

#endif /* texture_h */
