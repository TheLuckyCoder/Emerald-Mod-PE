#pragma once

#include "../Feature.h"
class BlockSource;
class BlockPos;
class Random;

class DoubePlantFeature : public Feature {
public:
	virtual ~DoublePlantFeature(); 
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
	virtual bool place(BlockSource&, const BlockPos&, Random&, int) const = 0;
};
