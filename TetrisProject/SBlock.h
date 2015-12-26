#pragma once

#include "Graphics.h"
#include "Block.h"

class SBlock : public Block
{
public:
	SBlock();
	~SBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
};

