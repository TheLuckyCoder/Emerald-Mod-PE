#pragma once

#include "mcpe/block/Block.h"

class TntBlock : public Block
{
public:
	TntBlock(std::string const&,int);
public:
	virtual void onExploded(BlockSource&, BlockPos const&, Entity*)const;
	virtual int getResourceCount(Random&, int, int)const;
	virtual void onRedstoneUpdate(BlockSource&, BlockPos const&, int, bool)const;
	virtual bool use(Player&, BlockPos const&)const;
	virtual void destroy(BlockSource&, BlockPos const&, int, Entity*)const;
	virtual void onPlace(BlockSource&, BlockPos const&)const;
	virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char)const;
	virtual void onLoaded(BlockSource&, BlockPos const&)const;
};
