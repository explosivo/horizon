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

void Entity::getBounds()
{

}
