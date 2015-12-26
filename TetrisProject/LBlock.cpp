#include "LBlock.h"



LBlock::LBlock()
{
}


LBlock::~LBlock()
{
}

void LBlock::Unload()
{

}
void LBlock::Render(Graphics* gfx)
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	if (mDirection == UP)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 100, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == RIGHT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 100, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y + 100, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == LEFT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 100, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}

}