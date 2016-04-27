#pragma once

#include "mcpe/world/level/block/Block.h"

class DoubleSlabBlock : public Block
{
public:
	DoubleSlabBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
};
