#pragma once

#include "minecraftpe/world/level/block/Block.h"

class EmeraldWoodBlock : public Block
{
public:
	EmeraldWoodBlock(const std::string &name, short id);

	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, Vec3 const&, int) const;
};

