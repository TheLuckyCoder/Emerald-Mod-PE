#pragma once

#include "Block.h"

class FenceBlock : public Block
{
public:
	FenceBlock(const std::string&, int, const Material&);

	virtual bool connectsTo(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool isFenceBlock() const;
	virtual AABB const& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	virtual bool use(Player&, const BlockPos&) const;
	virtual bool canProvideSupport(BlockSource&, const BlockPos&, signed char, BlockSupportType) const;
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int)const;
	virtual bool canBeSilkTouched() const;
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&, Entity*) const;
};

