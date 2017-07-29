#pragma once

#include "Block.h"

class SlabBlock : public Block
{
public:
	SlabBlock(const std::string&, int, bool, const Material&);

	virtual ~SlabBlock();
	virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&) const;
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual void* getMobToSpawn(BlockSource&, BlockPos&, int, int) const;
	virtual void shouldRenderFace(const BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool) const;
	virtual bool canBeSilkTouched() const;

	bool isBottomSlab(int);
	bool isBottomSlab(BlockSource&, const BlockPos&) const;
};
