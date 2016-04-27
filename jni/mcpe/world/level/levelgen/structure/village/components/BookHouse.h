#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class BookHouse : public VillagePiece {
public:
	BookHouse();
	BookHouse(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~BookHouse();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
