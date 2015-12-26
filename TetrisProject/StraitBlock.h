#pragma once
#include "Block.h"
#include "Graphics.h"

class StraitBlock : public Block
{
public:
	StraitBlock();
	~StraitBlock();

	void Unload() override;
	void Render(Graphics* gfx) override;
	void Update() override;
	void Left() override;
	void Right() override;
	void RotateClockwise() override;
};

