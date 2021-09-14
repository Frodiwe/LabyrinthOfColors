//
//  level_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.09.21.
//

#ifndef level_kit_hpp
#define level_kit_hpp

#include <string_view>

class Level;
class SDL_Renderer;

class LevelKit
{
public:
	Level create_test_level(SDL_Renderer* renderer, std::string_view cell_texture_path) const;
};

#endif /* level_kit_hpp */
