//
//  key_handler.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef key_handler_hpp
#define key_handler_hpp

class SDL_KeyboardEvent;

class KeyHandler
{
public:
	void process(const SDL_KeyboardEvent& key) const;
};

#endif /* key_handler_hpp */
