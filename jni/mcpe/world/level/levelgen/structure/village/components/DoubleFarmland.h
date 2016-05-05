#pragma once

#include "../VillagePiece.h"

class DoubleFarmland : public VillagePiece {
public:
	DoubleFarmland();
	DoubleFarmland(StartPiece*, int, Random&, const BoundingBox&, int);
	
	virtual ~DoubleFarmland();
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
