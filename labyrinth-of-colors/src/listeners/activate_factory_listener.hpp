//
//  activate_factory_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef activate_factory_listener_hpp
#define activate_factory_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class BlendingSystem;

class ActivateFactoryListener : public Listener
{
private:
    entt::registry& registry;
    
    BlendingSystem* blending_system;
    
public:
    ActivateFactoryListener(entt::registry& registry, BlendingSystem* blending_system) : registry{registry}, blending_system{blending_system}
    { }
    
    void operator()(Event* event);
};

#endif /* activate_factory_listener_hpp */
