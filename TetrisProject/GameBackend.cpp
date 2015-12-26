#include "GameBackend.h"

GameBackend::GameBackend()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mGrid[i][j] = false;
		}
	}
}


GameBackend::~GameBackend()
{
}
