#define NOMINMAX

#include "StraitBlock.h"

#include "GameConstants.cpp"
#include "GameController.h"
#include <algorithm>

StraitBlock::StraitBlock()
{
}


StraitBlock::~StraitBlock()
{
}


void StraitBlock::Unload()
{

}

void StraitBlock::Render(Graphics* gfx)
{
	if (mDirection == LEFT || mDirection == RIGHT)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - BLOCK_HEIGHT, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + BLOCK_HEIGHT, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + (2*BLOCK_HEIGHT), y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == UP || mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}

void StraitBlock::Update()
{
	y += ySpeed;

	int index = static_cast<int>(std::floor(x/BLOCK_WIDTH));

	if (mDirection == UP || mDirection == DOWN)
	{
		int height = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		if (y + 2*BLOCK_HEIGHT >= height)
		{
			y = height - 2*BLOCK_HEIGHT;
			GameController::mHeights[index] += 4;
			mFinished = true;
		}
	}
	else if (mDirection == LEFT || mDirection == RIGHT)
	{
		int height1 = WINDOW_HEIGHT - (GameController::mHeights[index - 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height2 = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height3 = WINDOW_HEIGHT - (GameController::mHeights[index + 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height4 = WINDOW_HEIGHT - (GameController::mHeights[index + 2] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		int select = std::min( std::min( std::min(height1, height2), height3), height4);


		if (y >= height1 && height1 == select)
		{
			y = height1;
			GameController::mHeights[index - 1] += 1;
			GameController::mHeights[index] = GameController::mHeights[index - 1];
			GameController::mHeights[index + 1] = GameController::mHeights[index - 1];
			GameController::mHeights[index + 2] = GameController::mHeights[index - 1];
			mFinished = true;
		}
		else if (y >= height2 && height2 == select)
		{
			y = height2;
			GameController::mHeights[index] += 1;
			GameController::mHeights[index - 1] = GameController::mHeights[index];
			GameController::mHeights[index + 1] = GameController::mHeights[index];
			GameController::mHeights[index + 2] = GameController::mHeights[index];
			mFinished = true;
		}
		else if (y >= height3 && height3 == select)
		{
			y = height3;
			GameController::mHeights[index + 1] += 1;
			GameController::mHeights[index - 1] = GameController::mHeights[index + 1];
			GameController::mHeights[index] = GameController::mHeights[index + 1];
			GameController::mHeights[index + 2] = GameController::mHeights[index + 1];
			mFinished = true;
		}
		else if (y >= height4 && height4 == select)
		{
			y = height4;
			GameController::mHeights[index + 2] += 1;
			GameController::mHeights[index - 1] = GameController::mHeights[index + 2];
			GameController::mHeights[index] = GameController::mHeights[index + 2];
			GameController::mHeights[index + 1] = GameController::mHeights[index + 2];
			mFinished = true;
		}
	}
}


void StraitBlock::Left()
{
	x -= BLOCK_WIDTH;
	if (mDirection == LEFT || mDirection == RIGHT)
	{
		if (x <= BLOCK_WIDTH)
		{
			x = BLOCK_WIDTH;
		}
	}
	else if (mDirection == UP || DOWN)
	{
		if (x <= 0)
		{
			x = 0;
		}
	}
}

void StraitBlock::Right()
{
	x += BLOCK_WIDTH;
	if (mDirection == LEFT || mDirection == RIGHT)
	{
		if (x >= WINDOW_WIDTH - 3*BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - 3*BLOCK_WIDTH;
		}
	}
	else if (mDirection == UP || DOWN)
	{
		if (x >= WINDOW_WIDTH - BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - BLOCK_WIDTH;
		}
	}
}

void StraitBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		if (x + 2*BLOCK_WIDTH < WINDOW_WIDTH)
		{
			mDirection = RIGHT;
		}
	}
	else if (mDirection == RIGHT)
	{
		mDirection = UP;
	}
}