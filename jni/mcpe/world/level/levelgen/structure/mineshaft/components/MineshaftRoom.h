#pragma once

#include "../MineshaftPiece.h"
class MineshaftData;
class BlockSource;
class BoundingBox;
class Random;
class CompoundTag;

class MineshaftRoom : public MineshaftPiece {
public:
	MineshaftData& data;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	MineshaftRoom(MineshaftData&);
	MineshaftRoom(MineshaftData&, int, Random&, int, int);

	~MineshaftRoom();
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
