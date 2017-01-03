#pragma once

#include "Block.h"

class TorchBlock : public Block
{
public:
	TorchBlock(const std::string&, int);

	virtual ~TorchBlock();
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual int getIconYOffset() const;
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual bool canBeSilkTouched() const;
};
