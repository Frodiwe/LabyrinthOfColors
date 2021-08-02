//
//  texture.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.07.21.
//

#ifndef texture_h
#define texture_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Texture
{
public:
	Texture(SDL_Renderer* renderer, std::string_view path)
		: texture{this->load_texture(renderer, path)},
		  renderer{renderer},
		  frame{}
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
	
	void render()
	{
		SDL_Rect render_rect{this->frame.x, this->frame.y, this->frame.w, this->frame.h};
		
		SDL_RenderCopy(this->renderer, this->texture, &this->frame, &render_rect);
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
