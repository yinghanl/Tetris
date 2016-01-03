#include "SquareBlock.h"



SquareBlock::SquareBlock()
{
}


SquareBlock::~SquareBlock()
{
}


void SquareBlock::Load()
{
	Block::Load();

	mComponents[0].x = 5;
	mComponents[0].y = 1;
	mComponents[1].x = 4;
	mComponents[1].y = 1;
	mComponents[2].x = 5;
	mComponents[2].y = 0;
	mComponents[3].x = 4;
	mComponents[3].y = 0;
}


void SquareBlock::Unload()
{

}


void SquareBlock::RotateClockwise()
{

}