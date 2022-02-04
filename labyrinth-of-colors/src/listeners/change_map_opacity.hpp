//
//  change_map_opacity.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#ifndef change_map_opacity_hpp
#define change_map_opacity_hpp

#include "src/listeners/listener.h"

#include "third_party/entt/entity/registry.hpp"

class ChangeMapOpacity : public Listener
{
private:
    entt::registry& registry;
    
public:
    ChangeMapOpacity(entt::registry& registry) : registry{registry}
    { }
    
    void operator()(Event* event);
};

#endif /* change_map_opacity_hpp */
