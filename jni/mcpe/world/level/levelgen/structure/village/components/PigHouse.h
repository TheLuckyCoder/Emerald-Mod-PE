#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class PigHouse : public VillagePiece {
public:
	PigHouse();
	PigHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~PigHouse();
	virtual int getVillagerProfession(int);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
