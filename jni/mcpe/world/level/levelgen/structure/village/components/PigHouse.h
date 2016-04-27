#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class PigHouse : public VillagePiece {
public:
	PigHouse();
	PigHouse(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~SmallHut();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	int getVillagerProfession(int);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
