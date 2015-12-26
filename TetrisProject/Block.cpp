#include "Block.h"

#include "GameConstants.cpp"

void Block::Load()
{
	mFinished = false;
	mDirection = UP;
	y = 0.0f;
	x = 200.0f;
	ySpeed = 1.0f;
}

void Block::Update()
{
	y += ySpeed;
	if (y >= WINDOW_HEIGHT)
	{
		y = 550;
		mFinished = true;
	}
}

void Block::Left()
{
	x -= 50;
	if (x <= 0)
	{
		x = 0;
	}
}

void Block::Right()
{
	x += 50;
	if (x >= 800)
	{
		x = 800;
	}
}

void Block::Down(bool key)
{
	if (key == true)
	{
		ySpeed = 5.0f;
	}
	else
	{
		ySpeed = 1.0f;
	}
}

void Block::RotateClockwise()
{
	if (mDirection == UP)
	{
		mDirection = RIGHT;
	}
	else if (mDirection == RIGHT)
	{
		mDirection = DOWN;
	}
	else if (mDirection == DOWN)
	{
		mDirection = LEFT;
	}
	else if (mDirection == LEFT)
	{
		mDirection = UP;
	}
}

void Block::Drop()
{
	y = 600;
	mFinished = true;
}