//
//  Player.h
//
//  Created by Zach Nickell on 11/27/14.
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

		virtual void update(int delta);
	//	virtual void render();
	};
}

#endif
