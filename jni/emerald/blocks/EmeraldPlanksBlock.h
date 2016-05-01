#pragma once

#include "mcpe/world/level/block/Block.h"

class EmeraldPlanksBlock : public Block
{
public:
	EmeraldPlanksBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
