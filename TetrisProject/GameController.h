#pragma once

#include "Graphics.h"
#include "Block.h"

#include <vector>

class GameController
{

public:
	enum BlockType
	{
		STRAIT,
		SQUARE,
		Z,
		S,
		L,
		J,
		T,
		EMPTY
	};

public:
	static void LoadInitialLevel(Block* block);
	static void SwitchLevel(Block* block);
	
	static void Render(Graphics* gfx);
	static void Update();

	static void Init();

	static void Left();

	static void Right();

	static void Down(bool key);

	static void Up();

	static void Drop();

	static void FinishedBlock();

	static int mHeights[10];

	static BlockType mBlocks[10][20];

private:
	GameController() { }; //Singleton Class

	~GameController() { };

	static Block* mCurrentBlock;
	static bool mLoading;

	static void CheckLineClears();

	static void GenerateBlock();

	static void GameOver();
};

