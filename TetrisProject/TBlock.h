#pragma once

#include "Graphics.h"
#include "Block.h"

class TBlock : public Block
{
public:
	TBlock();
	~TBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
};

