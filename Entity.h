//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#ifndef __Entity__

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#elif defined __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#elif defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

namespace dg
{
	class Entity
	{
	public:
		Entity();
		~Entity();

		double x;
		double y;

		int xVel;
		int yVel;
		int speed;

		int w;
		int h;

		int health;

		virtual void update(int delta);
		virtual void render();
		SDL_Rect getBounds();
	};
}

#endif
