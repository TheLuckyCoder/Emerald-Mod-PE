#pragma once

#include "mcpe/world/level/block/Block.h"

class EmeraldBrickBlock : public Block
{
public:
	EmeraldBrickBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
