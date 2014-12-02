//
//  Horizon
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#include "Input.h"

using namespace dg;

bool Input::upPressed = false;
bool Input::downPressed = false;
bool Input::leftPressed = false;
bool Input::rightPressed = false;
bool Input::jumpPressed = false;

Input::Input()
{

}

Input::~Input()
{

}

void Input::updateInput(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w:
				upPressed = true;
				break;
			case SDLK_a:
				leftPressed = true;
				break;
			case SDLK_s:
				downPressed = true;
				break;
			case SDLK_d:
				rightPressed = true;
				break;
			case SDLK_SPACE:
				jumpPressed = true;
				break;
		}
	}
	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w:
				upPressed = false; 
				break;
			case SDLK_a:
				leftPressed = false;
				break;
			case SDLK_s:
				downPressed = false;
				break;
			case SDLK_d:
				rightPressed = false;
				break;
			case SDLK_SPACE:
				jumpPressed = false;
				break;
		}
	}
}
