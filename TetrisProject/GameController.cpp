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
GameController::BlockType GameController::mNextBlock;

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

	int random = rand();

	switch (random)
	{
	case 0:
		mNextBlock = STRAIT;
		break;
	case 1:
		mNextBlock = T;
		break;
	case 2:
		mNextBlock = SQUARE;
		break;
	case 3:
		mNextBlock = J;
		break;
	case 4:
		mNextBlock = L;
		break;
	case 5:
		mNextBlock = S;
		break;
	case 6:
		mNextBlock = Z;
		break;
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

	gfx->DrawTextBox(350.0f, 50.0f, ss.str());

	switch (mNextBlock)
	{
	case STRAIT:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + 3 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 3 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		break;
	case T:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f - BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f - BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		break;
	case SQUARE:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		break;
	case J:
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		break;
	case L:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		break;
	case S:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		break;
	case Z:
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		break;
	}


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

	if (mNextBlock == STRAIT)
	{
		GameController::SwitchLevel(new StraitBlock());
	}
	else if (mNextBlock == T)
	{
		GameController::SwitchLevel(new TBlock());
	}
	else if (mNextBlock == SQUARE)
	{
		GameController::SwitchLevel(new SquareBlock());
	}
	else if (mNextBlock == J)
	{
		GameController::SwitchLevel(new JBlock());
	}
	else if (mNextBlock == L)
	{
		GameController::SwitchLevel(new LBlock());
	}
	else if (mNextBlock == S)
	{
		GameController::SwitchLevel(new SBlock());
	}
	else if (mNextBlock == Z)
	{
		GameController::SwitchLevel(new ZBlock());
	}

	switch (random)
	{
	case 0:
		mNextBlock = STRAIT;
		break;
	case 1:
		mNextBlock = T;
		break;
	case 2:
		mNextBlock = SQUARE;
		break;
	case 3:
		mNextBlock = J;
		break;
	case 4:
		mNextBlock = L;
		break;
	case 5:
		mNextBlock = S;
		break;
	case 6:
		mNextBlock = Z;
		break;
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