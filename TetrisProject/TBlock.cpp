#include "TBlock.h"



TBlock::TBlock()
{
}


TBlock::~TBlock()
{
}

void TBlock::Unload()
{

}
void TBlock::Render(Graphics* gfx)
{
	if (mDirection == UP)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (mDirection == RIGHT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (mDirection == LEFT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}

}