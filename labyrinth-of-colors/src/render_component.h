//
//  RenderComponent.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef render_component_h
#define render_component_h

class RenderComponent
{
public:
	virtual void render(const int x, const int y) = 0;
};

#endif /* render_component_h */
