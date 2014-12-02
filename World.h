//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#ifndef __World__
#define __World__

#include "Player.h"

namespace dg
{
	class World
	{
	public:
		World();
		~World();

		Player player;

		void update(int delta);
		void render();
	};
}

#endif