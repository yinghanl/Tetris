#include "Block.h"

#include "GameConstants.cpp"
#include "GameController.h"

void Block::Load()
{
	mFinished = false;
	mDirection = UP;
	ySpeed = 5;
	mCurrentY = 0;
}

void Block::Render(Graphics * gfx)
{
	for (int i = 0; i < 4; i++)
	{
		gfx->DrawRectangle(mComponents[i].x * BLOCK_WIDTH, mComponents[i].y * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f);
		gfx->FillRectangle(mComponents[i].x * BLOCK_WIDTH, mComponents[i].y * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, mRed, mGreen, mBlue, 1.0f);
	}
}

void Block::Update()
{
	mCurrentY += ySpeed;

	if (mCurrentY < 100)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		//int y = BLOCK_HEIGHT * (mComponents[i].y + 1) + BLOCK_HEIGHT;
		int x = mComponents[i].x;
		int y = mComponents[i].y + 1;
		if (GameController::mBlocks[x][y] != GameController::BlockType::EMPTY || y == 20)
		{
			mFinished = true;
			return;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		mComponents[i].y++;
	}
	mCurrentY = 0;
}

void Block::Left()
{
	for (int i = 0; i < 4; i++)
	{
		int x = mComponents[i].x;
		x -= 1;

		if (x < 0)
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		mComponents[i].x -= 1;
	}
}

void Block::Right()
{
	for (int i = 0; i < 4; i++)
	{
		int x = mComponents[i].x;
		x += 1;

		if (x * BLOCK_WIDTH > WINDOW_WIDTH - BLOCK_WIDTH)
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		mComponents[i].x += 1;
	}
}

void Block::Down(bool key)
{
	if (key == true)
	{
		ySpeed = 20;
	}
	else
	{
		ySpeed = 5;
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
	while (!mFinished)
	{
		Update();
	}
}