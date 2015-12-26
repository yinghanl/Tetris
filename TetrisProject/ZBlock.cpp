#include "ZBlock.h"



ZBlock::ZBlock()
{
}


ZBlock::~ZBlock()
{
}

void ZBlock::Unload()
{

}
void ZBlock::Render(Graphics* gfx)
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	if (mDirection == UP || mDirection == DOWN)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y - 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x - 50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	}
	else if (mDirection == RIGHT || mDirection == LEFT)
	{
		gfx->DrawRectangle(x, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x-50, y, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x, y+50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gfx->DrawRectangle(x+50, y + 50, 50.0f, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}

}

void ZBlock::Update()
{
	y += ySpeed;
	if (mDirection == UP && y >= 500)
	{
		y = 500;
		mFinished = true;
	}
}