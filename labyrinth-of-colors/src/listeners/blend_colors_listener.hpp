//
//  blend_colors_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.02.22.
//

#ifndef blend_colors_listener_hpp
#define blend_colors_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class Event;
class ColorFactorySystem;
class ItemsKit;
class InventorySystem;
class PlayerSystem;

class BlendColorsListener : public Listener
{
private:
    entt::registry& registry;
    
    ColorFactorySystem* color_factory_system;
    
    ItemsKit* items_kit;
    
    InventorySystem* inventory_system;
    
    PlayerSystem* player_system;
    
public:
    BlendColorsListener(entt::registry& registry, ColorFactorySystem* cf_s, ItemsKit* it_k, InventorySystem* in_s, PlayerSystem* pl_s)
    : registry{registry}, color_factory_system{cf_s}, items_kit{it_k}, inventory_system{in_s}, player_system{pl_s}
    { }
    
    void operator()(Event* event) override;
};

#endif /* blend_colors_listener_hpp */
