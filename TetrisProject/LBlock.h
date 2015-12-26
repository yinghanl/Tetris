#pragma once

#include "Graphics.h"
#include "Block.h"

class LBlock : public Block
{
public:
	LBlock();
	~LBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
};

