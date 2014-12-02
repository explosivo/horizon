//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#ifndef __Player__
#define __Player__

#include "Entity.h"
#include "Input.h"

namespace dg
{
	class Player : public Entity
	{
		public:
		Player();
		~Player();

		int jumpVel;
		bool grounded;

		virtual void update(int delta);
	//	virtual void render();
	};
}

#endif
