//
//  game.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.11.21.
//

#ifndef game_hpp
#define game_hpp

#include <stdlib.h>
#include <string>

#include "third_party/entt/entity/registry.hpp"

struct MapPosition;

class LevelConfig;
class Window;
class SDL_Renderer;
class EventsQueue;

class Game
{
private:
	LevelConfig get_level_config(const std::string&) const;
    
    entt::entity get_cell_at(const MapPosition&);
	
public:
	Game(Window* window, EventsQueue* events_queue);
	
	void render(SDL_Renderer* renderer);
	
	~Game();
};

#endif /* game_hpp */
