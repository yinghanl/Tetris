#define NOMINMAX

#include "JBlock.h"

#include "GameConstants.cpp"
#include "GameController.h"
#include <algorithm>

JBlock::JBlock()
{
}


void JBlock::Unload()
{
}

void JBlock::Render(Graphics* gfx)
{
	if (mDirection == UP)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - BLOCK_HEIGHT, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == RIGHT)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + BLOCK_WIDTH, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 2*BLOCK_WIDTH, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + BLOCK_HEIGHT, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == LEFT)
	{
		gfx->DrawRectangle(x, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - BLOCK_WIDTH, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 2*BLOCK_WIDTH, y, BLOCK_HEIGHT, BLOCK_WIDTH, 1.0f, 1.0f, 1.0f, 1.0f);
	}

}

void JBlock::Update()
{
	y += ySpeed;

	int index = static_cast<int>(std::floor(x / BLOCK_WIDTH));

	if (mDirection == UP)
	{
		int height1 = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height2 = WINDOW_HEIGHT - (GameController::mHeights[index - 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		int select = std::min(height1, height2);

		if (y >= height1 && select == height1)
		{
			y = height1;
			GameController::mHeights[index] += 3;
			GameController::mHeights[index - 1] = GameController::mHeights[index] - 2;
			mFinished = true;
		}
		else if (y >= height2 && select == height2)
		{
			y = height2;
			GameController::mHeights[index - 1] += 1;
			GameController::mHeights[index] = GameController::mHeights[index - 1] + 2;
			mFinished = true;
		}
	}
	else if (mDirection == RIGHT)
	{
		int height1 = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height2 = WINDOW_HEIGHT - (GameController::mHeights[index + 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height3 = WINDOW_HEIGHT - (GameController::mHeights[index + 2] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		int select = std::min( std::min(height1, height2), height3);

		if (y >= height1 && select == height1)
		{
			y = height1;
			GameController::mHeights[index] += 2;
			GameController::mHeights[index + 1] = GameController::mHeights[index] - 1;
			GameController::mHeights[index + 2] = GameController::mHeights[index] - 1;
			mFinished = true;
		}
		else if (y >= height2 && select == height2)
		{
			y = height2;
			GameController::mHeights[index + 1] += 1;
			GameController::mHeights[index] = GameController::mHeights[index + 1] + 1;
			GameController::mHeights[index + 2] = GameController::mHeights[index + 1];
			mFinished = true;
		}
		else if (y >= height3 && select == height3)
		{
			y = height3;
			GameController::mHeights[index + 2] += 1;
			GameController::mHeights[index] = GameController::mHeights[index + 2] + 1;
			GameController::mHeights[index + 1] = GameController::mHeights[index + 2];
			mFinished = true;
		}
	}
	else if (mDirection == DOWN)
	{
		int height1 = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - 3*BLOCK_HEIGHT; //3 blocks down
		int height2 = WINDOW_HEIGHT - (GameController::mHeights[index + 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		int select = std::min(height1, height2);

		if (y >= height1 && select == height1)
		{
			y = height1;
			GameController::mHeights[index] += 3;
			GameController::mHeights[index + 1] = GameController::mHeights[index];
			mFinished = true;
		}
		else if (y >= height2 && select == height2)
		{
			y = height2;
			GameController::mHeights[index + 1] += 1;
			GameController::mHeights[index] = GameController::mHeights[index + 1];
			mFinished = true;
		}
	}
	else if (mDirection == LEFT)
	{
		int height1 = WINDOW_HEIGHT - (GameController::mHeights[index] * BLOCK_HEIGHT) - 2 * BLOCK_HEIGHT; //3 blocks down
		int height2 = WINDOW_HEIGHT - (GameController::mHeights[index - 1] * BLOCK_HEIGHT) - BLOCK_HEIGHT;
		int height3 = WINDOW_HEIGHT - (GameController::mHeights[index - 2] * BLOCK_HEIGHT) - BLOCK_HEIGHT;

		int select = std::min(std::min(height1, height2), height3);

		if (y >= height1 && select == height1)
		{
			y = height1;
			GameController::mHeights[index] += 2;
			GameController::mHeights[index - 1] = GameController::mHeights[index];
			GameController::mHeights[index - 2] = GameController::mHeights[index];
			mFinished = true;
		}
		else if (y >= height2 && select == height2)
		{
			y = height2;
			GameController::mHeights[index - 1] += 1;
			GameController::mHeights[index] = GameController::mHeights[index - 1];
			GameController::mHeights[index - 2] = GameController::mHeights[index - 1];
			mFinished = true;
		}
		else if (y >= height3 && select == height3)
		{
			y = height3;
			GameController::mHeights[index - 2] += 1;
			GameController::mHeights[index] = GameController::mHeights[index - 2];
			GameController::mHeights[index - 1] = GameController::mHeights[index - 2];
			mFinished = true;
		}
	}
}

void JBlock::Left()
{
	x -= BLOCK_WIDTH;

	if (mDirection == UP)
	{
		if (x <= BLOCK_WIDTH)
		{
			x = BLOCK_WIDTH;
		}
	}
	else if (mDirection == RIGHT)
	{
		if (x <= 0)
		{
			x = 0;
		}
	}
	else if (mDirection == DOWN)
	{
		if (x <= 0)
		{
			x = 0;
		}
	}
	else if (mDirection == LEFT)
	{
		if (x <= 2*BLOCK_WIDTH)
		{
			x = 2 * BLOCK_WIDTH;
		}
	}
}

void JBlock::Right()
{
	x += BLOCK_WIDTH;

	if (mDirection == UP)
	{
		if (x >= WINDOW_WIDTH - BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - BLOCK_WIDTH;
		}
	}
	else if (mDirection == RIGHT)
	{
		if (x >= WINDOW_WIDTH - 3 * BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - 3 * BLOCK_WIDTH;
		}
	}
	else if (mDirection == DOWN)
	{
		if (x >= WINDOW_WIDTH - 2 * BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - 2 * BLOCK_WIDTH;
		}
	}
	else if (mDirection == LEFT)
	{
		if (x >= WINDOW_WIDTH - BLOCK_WIDTH)
		{
			x = WINDOW_WIDTH - BLOCK_WIDTH;
		}
	}
}

void JBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		if (x <= WINDOW_WIDTH - 3 * BLOCK_WIDTH)
		{
			mDirection = RIGHT;
		}
	}
	else if (mDirection == RIGHT)
	{
		mDirection = DOWN;
	}
	else if (mDirection == DOWN)
	{
		if (x >= 2 * BLOCK_WIDTH)
		{
			mDirection = LEFT;
		}
	}
	else if (mDirection == LEFT)
	{
		mDirection = UP;
	}
}