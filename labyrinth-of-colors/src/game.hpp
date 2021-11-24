//
//  game.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.11.21.
//

#ifndef game_hpp
#define game_hpp

#include <stdlib.h>

#include "third_party/entt/entity/registry.hpp"

class LevelConfig;
class Window;
class SDL_Renderer;

class Game
{
private:
	LevelConfig get_level_config(size_t) const;
	
public:
	Game(Window* window);
	
	void render(SDL_Renderer* renderer);
    
    entt::entity get_player();
	
	~Game();
};

#endif /* game_hpp */
