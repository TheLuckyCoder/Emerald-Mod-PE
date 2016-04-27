#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class LightPost : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	LightPost();
	LightPost(StartPiece*, int, Random&, BoundingBox const&, int);
	~LightPost();

	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
