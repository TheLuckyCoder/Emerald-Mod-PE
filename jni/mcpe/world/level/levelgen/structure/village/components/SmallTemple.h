#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class SmallTemple : public VillagePiece {
public:
	SmallTemple();
	SmallTemple(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~SmallTemple();
	virtual int getVillagerProfession(int);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
