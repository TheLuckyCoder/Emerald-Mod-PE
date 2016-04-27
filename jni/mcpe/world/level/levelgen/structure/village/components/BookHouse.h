#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class Random;

class BookHouse : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	BookHouse();
	BookHouse(StartPiece*, int, Random&, BoundingBox const&, int);
	~BookHouse();

	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
