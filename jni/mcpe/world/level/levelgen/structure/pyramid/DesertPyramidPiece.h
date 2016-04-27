#pragma once

#include "../StructurePiece.h"
class BoundingBox;
class BlockSource;
class CompoundTag;
class Random;

class DesertPyramidPiece : public StructurePiece {
public:
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	DesertPyramidPiece(Random&, int, int);

	~DesertPyramidPiece();
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	//Custom functions
	void genPyramidMineshaftCorridor(BlockSource*, Random&, BoundingBox const&);
};