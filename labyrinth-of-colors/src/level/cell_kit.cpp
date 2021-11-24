//
//  cell_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "cell_kit.hpp"

#include <SDL2/SDL.h>

#include "src/components/position.h"
#include "src/components/size.h"
#include "src/level/components/action.h"
#include "src/level/tags/cell.h"

#include "src/texture.h"
#include "src/rect.hpp"
#include "src/events_queue.hpp"
#include "src/event.h"

entt::entity CellKit::create_cell(SDL_Renderer* renderer, std::string_view texture_path, Rect frame, Rect target_frame, CellColor color, CellAction action) const
{
	const auto cell = registry.create();
	
    registry.emplace<Cell>(cell);
	registry.emplace<Position>(cell, target_frame.x, target_frame.y);
	registry.emplace<Size>(cell, target_frame.w, target_frame.h);
//	registry.emplace<Action>(cell, create_action(action));
	registry.emplace<CellColor>(cell, color);
	
	switch (color) {
		case CellColor::YELLOW:
		case CellColor::RED:
			registry.emplace<Texture>(cell, Texture(renderer, texture_path, frame));
			break;
			
		case CellColor::WALL:			
		default:
			break;
	};
	
	return cell;
}

std::function<void()> CellKit::create_action(CellAction action) const
{
	switch (action)
	{
		case CellAction::NONE:
			return [] { };
			
		case CellAction::START:
			return [] { EventsQueue::publish(Event::START_LEVEL); };
			
		case CellAction::EXIT:
			return [] { EventsQueue::publish(Event::EXIT_LEVEL); };
			
		case CellAction::RED_PAINT:
			return [] { EventsQueue::publish(Event::GIVE_PAINT, CellColor::RED); };
	}
}
