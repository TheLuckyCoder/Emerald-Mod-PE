#pragma once

#include "Feature.h"
class BlockSource;
class BlockPos;
class FullBlock;
class Random;

class FlowerFeature : public Feature {
public:
	BlockID id; // 9

	FlowerFeature(BlockID);

	virtual ~FlowerFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
	virtual bool placeFlower(BlockSource&, BlockPos const&, FullBlock, Random&) const;
};
