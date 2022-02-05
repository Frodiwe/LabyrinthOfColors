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
class View;

class Game
{
private:
    EventsQueue* events_queue;
    
	LevelConfig get_level_config(const std::string&) const;
    
    entt::entity get_cell_at(const MapPosition&);
    
    void subscribe_listeners();
    
    void create_level(LevelConfig config);
    
    entt::entity create_player(MapPosition start);
	
public:
	Game(Window* window, EventsQueue* events_queue);
	
	void render(SDL_Renderer* renderer);
    
    static View* get_view();
	
	~Game();
};

#endif /* game_hpp */
