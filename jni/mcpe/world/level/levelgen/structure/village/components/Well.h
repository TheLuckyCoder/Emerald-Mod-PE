#pragma once

#include "../VillagePiece.h"
class BlockSource;
class BoundingBox;
class Random;

class Well : public VillagePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	Well();
	Well(StartPiece*, int, Random&, int, int);
	Well(StartPiece*, int, Random&, BoundingBox const&, int);
	~Well();

	void postProcess(BlockSource*, Random&, BoundingBox const&);
};
