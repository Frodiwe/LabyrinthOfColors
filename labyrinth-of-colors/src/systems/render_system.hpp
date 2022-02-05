//
//  render_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 23.11.21.
//

#ifndef render_system_hpp
#define render_system_hpp

#include "third_party/entt/entity/registry.hpp"

struct SDL_Renderer;

class RenderSystem
{
private:
    entt::registry& registry;
    
public:
    RenderSystem(entt::registry& registry) : registry{registry}
    { }
    
    void render_map(SDL_Renderer* renderer);
    
    void render_items(SDL_Renderer* renderer);
    
    void render_player(SDL_Renderer* renderer);
    
    void render_inventory(SDL_Renderer* renderer);
};

#endif /* render_system_hpp */
