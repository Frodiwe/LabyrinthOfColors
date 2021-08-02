//
//  player.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef player_h
#define player_h

class Player
{
public:
	bool can_step_on(const Cell& cell);

	void move(const Cell& to_cell);
}

#endif /* player_h */
