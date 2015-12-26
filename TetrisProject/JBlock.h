#pragma once

#include "Graphics.h"
#include "Block.h"

class JBlock : public Block
{
public:
	JBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
	void Update() override;
	void Left() override;
	void Right() override;
	void RotateClockwise() override;
};

