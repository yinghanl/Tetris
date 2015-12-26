#pragma once
#include "Graphics.h"

class Block
{
public:

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	bool mLoading;
	float x;
	float y;
	float ySpeed;
	Direction mDirection;
	bool mFinished;

	virtual void Load();
	virtual void Unload() = 0;
	virtual void Render(Graphics* gfx) = 0;
	virtual void Update();
	virtual void Left();
	virtual void Right();
	virtual void RotateClockwise();
	virtual void Down(bool key);
	virtual void Drop();
};

