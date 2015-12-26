#include "GameController.h"


bool GameController::mLoading;
Block* GameController::mCurrentBlock;
std::vector<Block*> GameController::mBlocks;
int GameController::mHeights[10];

void GameController::Init()
{
	mLoading = true;
	mCurrentBlock = nullptr;
	mBlocks.clear();
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
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	for (Block* block : mBlocks)
	{
		block->Render(gfx);
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
		mBlocks.push_back(mCurrentBlock);
	}

	return mCurrentBlock->mFinished;
}
