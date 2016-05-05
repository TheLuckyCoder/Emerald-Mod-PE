#pragma once

#include "../VillagePiece.h"

class TwoRoomHouse : public VillagePiece {
public:
	TwoRoomHouse();
	TwoRoomHouse(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual TwoRoomHouse();
	virtual  postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
