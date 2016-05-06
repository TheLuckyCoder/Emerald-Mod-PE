#pragma once

#include "mcpe/world/level/block/DoorBlock.h"

class EmeraldDoorBlock : public DoorBlock
{
public:
	EmeraldDoorBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
};
