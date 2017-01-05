#pragma once

#include "Block.h"

class LadderBlock : public Block
{
public:
	LadderBlock(const std::string&, int);

	virtual ~LadderBlock();
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual bool isWaterBlocking() const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool) const;
	virtual bool canBeSilkTouched() const;
};
