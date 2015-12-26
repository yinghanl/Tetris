#pragma once

#include "Block.h"
#include "Graphics.h"
class SquareBlock : public Block
{
public:
	SquareBlock();
	~SquareBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
};

