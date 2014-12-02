//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#include "World.h"

using namespace dg;

World::World()
{

}

World::~World()
{

}

void World::update(int delta)
{
	player.update(delta);
}

void World::render()
{
	player.render();
}