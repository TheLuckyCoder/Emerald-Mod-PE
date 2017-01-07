#pragma once

#include "Block.h"

class StairBlock : public Block
{
public:
	StairBlock(const std::string&, int, const Block&, int);

	virtual ~StairBlock();
	virtual void tick(BlockSource&, const BlockPos&, Random&) const;
	virtual void addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&) const;
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual bool isStairBlock() const;
	virtual void onPlace(BlockSource&,const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void onStepOn(Entity&, const BlockPos&) const;
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual bool mayPick() const;
	virtual bool mayPick(BlockSource&, int, bool) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char) const;
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual void clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, int) const;
	virtual bool use(Player&, const BlockPos&) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual void attack(Player*, const BlockPos&) const;
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&) const;
	virtual int getVariant(int) const;
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual bool canBeSilkTouched() const;
};
