#pragma once

#include "mcpe/block/Block.h"

class FenceBlock : public Block
{
public:
	FenceBlock(std::string const&,int,Material const&);
public:
	virtual bool connectsTo(BlockSource&, BlockPos const&, BlockPos const&) const;
	virtual bool isFenceBlock() const;
	virtual AABB const& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool) const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual bool use(Player&, BlockPos const&)const;
	virtual bool canProvideSupport(BlockSource&, BlockPos const&, signed char, BlockSupportType) const;
	virtual const AABB& getAABB(BlockSource&, BlockPos const&, AABB&, int, bool, int)const;
	virtual bool canBeSilkTouched() const;
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual void addCollisionShapes(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&, Entity*) const;
};
