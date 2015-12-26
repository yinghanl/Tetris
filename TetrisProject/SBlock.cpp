#include "SBlock.h"



SBlock::SBlock()
{
}


SBlock::~SBlock()
{
}

void SBlock::Unload()
{

}
void SBlock::Render(Graphics* gfx)
{
	if (mDirection == UP || mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y-50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x+50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x + 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else if (mDirection == RIGHT || mDirection == LEFT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x+50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y+50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x-50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	}

}