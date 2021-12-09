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

#include "src/rect.hpp"

class Texture
{
public:
	Texture(std::string_view path, Rect frame)
		: path{path},
		  frame{frame.x, frame.y, static_cast<int32_t>(frame.w), static_cast<int32_t>(frame.h)}
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
	
	void render(SDL_Renderer* renderer, const Rect& target_rect)
	{
        if (not is_loaded()) {
            texture = load_texture(renderer, path);
        }
        
		SDL_RenderCopy(renderer, this->texture, &this->frame, new SDL_Rect{target_rect.x, target_rect.y, static_cast<int32_t>(target_rect.w), static_cast<int32_t>(target_rect.h)});
	}
	
protected:
	SDL_Texture* texture = nullptr;
	SDL_Rect frame;
    std::string path;
	
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
