#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class LightPost : public VillagePiece {
public:
	LightPost();
	LightPost(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~LightPost();
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
