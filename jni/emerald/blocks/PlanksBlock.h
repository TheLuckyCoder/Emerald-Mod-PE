#pragma once

#include "mcpe/world/level/block/Block.h"

class PlanksBlock : public Block
{
public:
	PlanksBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
