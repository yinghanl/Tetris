#pragma once

#include "Graphics.h"
#include "Block.h"

class ZBlock : public Block
{
public:
	ZBlock();
	~ZBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
	void Update() override;
};

