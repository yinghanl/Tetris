#pragma once

#include "Graphics.h"
#include "Block.h"

#include <vector>

class GameController
{
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

	static bool FinishedBlock();

	static int mHeights[10];


private:
	GameController() { }; //Singleton Class

	static Block* mCurrentBlock;
	static bool mLoading;

	static std::vector<Block*> mBlocks;


};

