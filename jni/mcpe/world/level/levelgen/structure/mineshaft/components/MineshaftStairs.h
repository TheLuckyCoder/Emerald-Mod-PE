#pragma once

#include "../MineshaftPiece.h"
class MineshaftData;
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class MineshaftStairs : public MineshaftPiece {
public:
	MineshaftData& data;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	MineshaftStairs(MineshaftData&);
	MineshaftStairs(MineshaftData&, int, Random&, BoundingBox const&, int);

	~MineshaftStairs();
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
