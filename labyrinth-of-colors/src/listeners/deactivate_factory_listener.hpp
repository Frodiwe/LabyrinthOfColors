//
//  deactivate_factory_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef deactivate_factory_listener_hpp
#define deactivate_factory_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class BlendingSystem;

class DeactivateFactoryListener : public Listener
{
private:
    entt::registry& registry;
    
    BlendingSystem* blending_system;
    
public:
    DeactivateFactoryListener(entt::registry& registry, BlendingSystem* blending_system) : registry{registry}, blending_system{blending_system}
    { }
    
    void operator()(Event* event);
};

#endif /* deactivate_factory_listener_hpp */
