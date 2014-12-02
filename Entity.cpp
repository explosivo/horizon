//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#include "Entity.h"

using namespace dg;

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::update(int delta)
{

}

void Entity::render()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2d(x, y);
		glVertex2d(x + w, y);
		glVertex2d(x + w, y + h);
		glVertex2d(x, y + h);
	glEnd();
}

SDL_Rect Entity::getBounds()
{
	SDL_Rect rect;
	rect.x = (int) x;
	rect.y = (int) y;
	rect.w = w;
	rect.h = h;
	return rect;
}
