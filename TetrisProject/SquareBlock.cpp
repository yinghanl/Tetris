#include "SquareBlock.h"



SquareBlock::SquareBlock()
{
}


SquareBlock::~SquareBlock()
{
}

void SquareBlock::Unload()
{

}
void SquareBlock::Render(Graphics* gfx)
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	//gfx->DrawCircle(375.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	gfx->DrawRectangle(x + 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	gfx->DrawRectangle(x, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	gfx->DrawRectangle(x + 50, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);

}
