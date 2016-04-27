#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class SmallHut : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	SmallHut();
	SmallHut(StartPiece*, int, Random&, BoundingBox const&, int);
	~SmallHut();

	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
