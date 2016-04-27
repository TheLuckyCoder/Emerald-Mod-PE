#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class StraightRoad : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	StraightRoad();
	StraightRoad(StartPiece*, int, Random&, BoundingBox const&, int);
	~StraightRoad();

	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
