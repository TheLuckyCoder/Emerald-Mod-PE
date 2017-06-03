#pragma once

#include "Block.h"

class ThinFenceBlock : public Block
{
public:
	ThinFenceBlock(std::string const&, int, Material const&, bool);
	
	virtual void addAABBs(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&) const;
	virtual void addCollisionShapes(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&, Entity*) const;
	virtual short getResource(Random&, int, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, BlockPos const&, int) const;
	virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
	virtual std::string buildDescriptionName(unsigned char) const;
	virtual const AABB& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool) const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char) const;

	bool attachsTo(int) const;
};
