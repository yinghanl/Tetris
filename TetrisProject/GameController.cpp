#include "GameController.h"
#include "GameConstants.cpp"


bool GameController::mLoading;
Block* GameController::mCurrentBlock;
int GameController::mHeights[10];
bool GameController::mBlocks[10][20];

void GameController::Init()
{
	mLoading = true;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mBlocks[i][j] = false;
		}
	}

	mCurrentBlock = nullptr;
	for (int i = 0; i < 10; i++)
	{
		mHeights[i] = 0;
	}

	mLoading = false;
}

void GameController::LoadInitialLevel(Block* block)
{
	mLoading = true;
	block->Load();
	mCurrentBlock = block;
	mLoading = false;
}
void GameController::SwitchLevel(Block* block)
{
	mLoading = true;
	mCurrentBlock->Unload();
	block->Load();
	mCurrentBlock = block;
	mLoading = false;
}

void GameController::Render(Graphics* gfx)
{
	gfx->ClearScreen(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (mBlocks[i][j] == true)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f);
			}
		}
	}

	mCurrentBlock->Render(gfx);
}

void GameController::Update()
{
	if (mLoading == true)
	{
		return;
	}
	mCurrentBlock->Update();
}

void GameController::Left()
{
	mCurrentBlock->Left();
}

void GameController::Right()
{
	mCurrentBlock->Right();
}

void GameController::Down(bool key)
{
	mCurrentBlock->Down(key);
}

void GameController::Up()
{
	mCurrentBlock->RotateClockwise();
}

void GameController::Drop()
{
	mCurrentBlock->Drop();
}

bool GameController::FinishedBlock()
{
	if (mCurrentBlock->mFinished)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = mCurrentBlock->mComponents[i].x;
			int y = mCurrentBlock->mComponents[i].y;

			mBlocks[x][y] = true;
		}
		CheckLineClears();
	}

	return mCurrentBlock->mFinished;
}

void GameController::CheckLineClears()
{
	int numberOfClearedLines = 0;

	for (int i = 19; i >= 0; i--)
	{
		int countBlocks = 0;
		for (int j = 0; j < 10; j++)
		{
			if (mBlocks[j][i] == true)
			{
				countBlocks++;
			}
		}
		if (countBlocks == 10)
		{

			numberOfClearedLines++;
			for (int j = 0; j < 10; j++)
			{
				mBlocks[j][i] = false;
			}

			for (int k = i; k >= 1; k--)
			{
				for (int j = 0; j < 10; j++)
				{
					mBlocks[j][k] = mBlocks[j][k - 1];
				}
			}
			i++;
		}
	}
}