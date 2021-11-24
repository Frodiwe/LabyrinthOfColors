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
#include "src/systems/movement_system.hpp"
#include "src/systems/render_system.hpp"

entt::registry DI::registry;

CellKit* DI::cell_kit = new CellKit(DI::registry);

MapKit* DI::map_kit = new MapKit(DI::registry, DI::cell_kit);

PlayerKit* DI::player_kit = new PlayerKit(DI::registry);

MovementSystem* DI::movement_system = new MovementSystem(DI::registry);

RenderSystem* DI::render_system = new RenderSystem(DI::registry);

MapKit* DI::get_map_kit()
{
	return map_kit;
}

PlayerKit* DI::get_player_kit()
{
	return player_kit;
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
