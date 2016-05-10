#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class SimpleHouse : public VillagePiece {
public:
	SimpleHouse();
	SimpleHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~SimpleHouse();
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	
	//Custom functions
	void genSimpleHouse(BlockSource*, Random&, BoundingBox const&);
};
