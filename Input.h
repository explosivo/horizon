//
//  Input.h
//
//  Created by Zach Nickell on 11/27/14.
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#ifndef __Input__
#define __Input__

#ifdef WIN32
#include <SDL.h>
#elif defined __APPLE__
#include <SDL2/SDL.h>
#elif defined __linux__
#include <SDL2/SDL.h>
#endif

namespace dg
{
	class Input
	{
	public:
		Input();
		~Input();

		static bool upPressed, downPressed, leftPressed, rightPressed;
		void updateInput(SDL_Event event);
	};
}

#endif
