#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class SmallTemple : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	SmallTemple();
	SmallTemple(StartPiece*, int, Random&, BoundingBox const&, int);
	~SmallTemple();

	int getVillagerProfession(int);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
	
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
