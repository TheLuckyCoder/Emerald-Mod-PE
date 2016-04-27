#pragma once

#include "mcpe/world/level/block/Block.h"

class BrickBlock : public Block
{
public:
	BrickBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
