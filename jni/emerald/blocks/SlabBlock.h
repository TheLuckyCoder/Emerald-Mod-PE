#pragma once

#include "mcpe/world/level/block/Block.h"

class SlabBlock : public Block
{
public:
	SlabBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
