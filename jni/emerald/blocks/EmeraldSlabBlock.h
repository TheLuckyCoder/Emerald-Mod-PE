#pragma once

#include "mcpe/world/level/block/SlabBlock.h"

class EmeraldSlabBlock : public SlabBlock
{
public:
	EmeraldSlabBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
