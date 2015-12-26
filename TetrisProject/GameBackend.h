#pragma once

#include "Block.h"

class GameBackend
{
public:
	GameBackend();
	~GameBackend();
private:
	bool mGrid[10][10];
	Block* mCurrentBlock;
};

