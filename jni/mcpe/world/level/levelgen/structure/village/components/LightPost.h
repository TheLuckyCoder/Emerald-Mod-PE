#pragma once

#include "../VillagePiece.h"
class BlockSource;
class BoundingBox;
class Random;

class LightPost : public VillagePiece {
public:
	LightPost();
	LightPost(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~LightPost();
	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
