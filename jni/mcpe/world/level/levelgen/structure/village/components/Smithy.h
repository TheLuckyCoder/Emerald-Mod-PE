#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class Smithy : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	Smithy();
	Smithy(StartPiece*, int, Random&, BoundingBox const&, int);
	~Smithy();
	
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
	
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

};
