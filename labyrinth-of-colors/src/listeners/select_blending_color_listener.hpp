//
//  select_blending_color_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.02.22.
//

#ifndef select_blending_color_listener_hpp
#define select_blending_color_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class Event;
class ColorFactorySystem;
class InventorySystem;

class SelectBlendingColorListener : public Listener
{
private:
    entt::registry& registry;
    
    ColorFactorySystem* color_factory_system;
    
    InventorySystem* inventory_system;
    
public:
    SelectBlendingColorListener(entt::registry& r, ColorFactorySystem* cf_s, InventorySystem* in_s) : registry{r}, color_factory_system{cf_s}, inventory_system{in_s}
    { }
    
    void operator()(Event* event) override;
};

#endif /* select_blending_color_listener_hpp */
