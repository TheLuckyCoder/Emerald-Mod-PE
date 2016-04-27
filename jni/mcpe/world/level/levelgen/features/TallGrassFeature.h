#pragma once

#include "Feature.h"
class BlockSource;
class BlockPos;
class Random;

class TallGrassFeature : public Feature {
public:
	BlockID id; // 9
	unsigned char data; // 10

	TallGrassFeature(BlockID, unsigned char);

	virtual ~TallGrassFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
	virtual bool place(BlockSource&, const BlockPos&, Random&, int, int) const = 0;
};
