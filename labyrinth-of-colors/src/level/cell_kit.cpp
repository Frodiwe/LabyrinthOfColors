//
//  cell_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#include "cell_kit.hpp"

#include <SDL2/SDL.h>

#include "src/level/cell.hpp"
#include "src/texture.h"
#include "src/render_component.h"
#include "src/rect.hpp"
#include "src/events_queue.hpp"
#include "src/event.h"

Cell* CellKit::create_cell(SDL_Renderer* renderer, std::string_view texture_path, Rect frame, Rect target_frame, CellColor color, CellAction action) const
{
	switch (color) {
		case CellColor::YELLOW:
		case CellColor::RED:
			return new Cell{
				std::unique_ptr<RenderComponent>{new Texture(renderer, texture_path, frame)},
				target_frame,
				color,
				create_action(action)
			};
			
		case CellColor::WALL:
			return new Cell{
				nullptr,
				target_frame,
				color,
				create_action(action)
			};
			
		default:
			break;
	};
}

std::function<void()> CellKit::create_action(CellAction action) const
{
	switch (action)
	{
		case CellAction::NONE:
			return nullptr;
			
		case CellAction::START:
			return [] { EventsQueue::publish(Event::START_LEVEL); };
			
		case CellAction::EXIT:
			return [] { EventsQueue::publish(Event::EXIT_LEVEL); };
			
		case CellAction::RED_PAINT:
			return [] { EventsQueue::publish(Event::GIVE_PAINT, CellColor::RED); };
	}
}
