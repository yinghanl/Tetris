#include "GameController.h"
#include "GameConstants.cpp"

#include "StraitBlock.h"
#include "TBlock.h"
#include "SquareBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "SBlock.h"
#include "ZBlock.h"

#include <sstream>

bool GameController::mLoading;
Block* GameController::mCurrentBlock;
int GameController::mHeights[10];
GameController::BlockType GameController::mBlocks[10][20];
int GameController::mScore;

void GameController::Init()
{
	mLoading = true;

	mScore = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mBlocks[i][j] = EMPTY;
		}
	}

	mCurrentBlock = nullptr;
	for (int i = 0; i < 10; i++)
	{
		mHeights[i] = 0;
	}

	GenerateBlock();

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
	block->Load();
	mCurrentBlock = block;
	mLoading = false;
}

void GameController::Render(Graphics* gfx)
{
	gfx->ClearScreen(1.0f, 1.0f, 1.0f);

	std::stringstream ss;
	ss << "Score: ";
	ss << mScore;

	gfx->DrawTextBox(350.0f, 200.0f, ss.str());

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f);
			if ((i + j) % 2 == 0)
			{
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.5f, 0.5f, 0.5f, 1.0f);
			}
			else
			{
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.4f, 0.4f, 0.4f, 1.0f);
			}

			if (mBlocks[i][j] == STRAIT)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == T)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == SQUARE)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == L)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == J)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == S)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
			}
			else if (mBlocks[i][j] == Z)
			{
				gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
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

void GameController::FinishedBlock()
{
	if (mCurrentBlock->mFinished)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = mCurrentBlock->mComponents[i].x;
			int y = mCurrentBlock->mComponents[i].y;

			if (y == 0) // Check For Game Over
			{
				GameOver();
				delete mCurrentBlock;

				GenerateBlock();
				return;
			}


			if (dynamic_cast<StraitBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = STRAIT;
			}
			else if (dynamic_cast<TBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = T;
			}
			else if (dynamic_cast<SquareBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = SQUARE;
			}
			else if (dynamic_cast<JBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = J;
			}
			else if (dynamic_cast<LBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = L;
			}
			else if (dynamic_cast<SBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = S;
			}
			else if (dynamic_cast<ZBlock*> (mCurrentBlock))
			{
				mBlocks[x][y] = Z;
			}

		}
		CheckLineClears();
		delete mCurrentBlock;

		GenerateBlock();
	}
}

void GameController::CheckLineClears()
{
	int numberOfClearedLines = 0;

	for (int i = 19; i >= 0; i--)
	{
		int countBlocks = 0;
		for (int j = 0; j < 10; j++)
		{
			if (mBlocks[j][i] != EMPTY)
			{
				countBlocks++;
			}
		}
		if (countBlocks == 10)
		{

			numberOfClearedLines++;
			for (int j = 0; j < 10; j++)
			{
				mBlocks[j][i] = EMPTY;
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

	if (numberOfClearedLines == 1)
	{
		mScore += 500;
	}
	else if (numberOfClearedLines == 2)
	{
		mScore += 2000;
	}
	else if (numberOfClearedLines == 3)
	{
		mScore += 4000;
	}
	else if (numberOfClearedLines == 4)
	{
		mScore += 10000;
	}
}

void GameController::GenerateBlock()
{
	int random = rand() % 7;

	if (random == 0)
	{
		GameController::SwitchLevel(new StraitBlock());
	}
	else if (random == 1)
	{
		GameController::SwitchLevel(new TBlock());
	}
	else if (random == 2)
	{
		GameController::SwitchLevel(new SquareBlock());
	}
	else if (random == 3)
	{
		GameController::SwitchLevel(new JBlock());
	}
	else if (random == 4)
	{
		GameController::SwitchLevel(new LBlock());
	}
	else if (random == 5)
	{
		GameController::SwitchLevel(new SBlock());
	}
	else if (random == 6)
	{
		GameController::SwitchLevel(new ZBlock());
	}
}

void GameController::GameOver()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mBlocks[i][j] = EMPTY;
		}
	}
}