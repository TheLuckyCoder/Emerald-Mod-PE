#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class StraightRoad : public VillagePiece {
public:
	StraightRoad();
	StraightRoad(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~Smithy();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
