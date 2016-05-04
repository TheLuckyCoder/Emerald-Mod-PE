#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class Random;

class BookHouse : public VillagePiece {
public:
	BookHouse();
	BookHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~BookHouse();
	virtual int getVillagerProfession(int);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
