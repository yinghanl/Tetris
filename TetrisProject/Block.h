#pragma once
#include "Graphics.h"

struct RenderableBlock
{
	int x;
	int y;
};

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
	int ySpeed;
	Direction mDirection;
	bool mFinished;
	int mCurrentY;
	RenderableBlock mComponents[4];

	virtual void Load();
	virtual void Unload() = 0;
	virtual void Render(Graphics* gfx);
	virtual void Update();
	virtual void Left();
	virtual void Right();
	virtual void RotateClockwise();
	virtual void Down(bool key);
	virtual void Drop();
};

