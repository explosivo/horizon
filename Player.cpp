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
	jumpVel = speed * 2;
	jumpTime = 0;
	grounded = false;
}

Player::~Player()
{

}

void Player::update(int delta)
{
	yVel += 2;

	if (y >= 480 - w)
	{
		yVel = 0;
		y = 480 - w;
		grounded = true;
	}

	if (Input::jumpPressed && grounded)
	{
		yVel -= jumpVel;
		grounded = false;
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
