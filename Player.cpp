//
//  Player.cpp
//
//  Created by Zach Nickell on 11/27/14.
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#include "Player.h"

using namespace dg;

Player::Player()
{
	x = 64;
	y = 64;
	w = 64;
	h = 64;
	xVel = 0;
	yVel = 0;
	speed = 10;
}

Player::~Player()
{

}

void Player::update(int delta)
{
	if (Input::upPressed && yVel > -speed)
	{
		yVel -= 1;
	}

	if (Input::downPressed && yVel < speed)
	{
	 yVel += 1;
	}

	if (!Input::upPressed && !Input::downPressed)
	{
		if (yVel < 0)
		{
			yVel += 1;
		}
		if (yVel > 0)
		{
			yVel -= 1;
		}
	}

	if (Input::leftPressed && xVel > -speed)
	{
		xVel -= 1;
	}

	if (Input::rightPressed && xVel < speed)
	{
		xVel += 1;
	}

	if (!Input::leftPressed && !Input::rightPressed)
	{
		if (xVel < 0)
		{
			xVel += 1;
		}
		if (xVel > 0)
		{
			xVel -= 1;
		}
	}

	x += xVel * delta * .1;
	y += yVel * delta * .1;
}
