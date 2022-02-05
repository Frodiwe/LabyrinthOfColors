//
//  di.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#include "di.hpp"

#include "src/level/cell_kit.hpp"
#include "src/level/map_kit.hpp"
#include "src/player_kit.hpp"
#include "src/items_kit.hpp"
#include "src/systems/movement_system.hpp"
#include "src/systems/render_system.hpp"
#include "src/systems/items_system.hpp"
#include "src/systems/inventory_system.hpp"
#include "src/events_queue.hpp"

entt::registry DI::registry;

CellKit* DI::cell_kit = new CellKit(DI::registry);

MapKit* DI::map_kit = new MapKit(DI::registry, DI::cell_kit);

PlayerKit* DI::player_kit = new PlayerKit(DI::registry);

ItemsKit* DI::items_kit = new ItemsKit(DI::registry);

MovementSystem* DI::movement_system = new MovementSystem(DI::registry);

RenderSystem* DI::render_system = new RenderSystem(DI::registry);

ItemsSystem* DI::items_system = new ItemsSystem(DI::registry);

InventorySystem* DI::inventory_system = new InventorySystem(DI::registry);

EventsQueue* DI::events_queue = new EventsQueue{};

MapKit* DI::get_map_kit()
{
	return map_kit;
}

PlayerKit* DI::get_player_kit()
{
	return player_kit;
}

ItemsKit* DI::get_items_kit()
{
    return items_kit;
}

entt::registry& DI::get_registry()
{
	return registry;
}

MovementSystem* DI::get_movement_system()
{
    return movement_system;
}

RenderSystem* DI::get_render_system()
{
    return render_system;
}

ItemsSystem* DI::get_items_system()
{
    return items_system;
}

InventorySystem* DI::get_inventory_system()
{
    return inventory_system;
}

EventsQueue* DI::get_events_queue()
{
    return events_queue;
}
