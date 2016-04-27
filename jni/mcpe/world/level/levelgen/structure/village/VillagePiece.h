#pragma once

#include "../StructurePiece.h"
#include "../StartPiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class FullBlock;
class PieceWeight;

class VillagePiece : public StructurePiece {
public:
	StartPiece* start;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;
	int x;
	int y;
	int z;

	VillagePiece();
	VillagePiece(StartPiece*, int);

	~VillagePiece();
	void spawnVillagers(BlockSource*, BoundingBox const&, int, int, int, int);
	bool biomeBlock(FullBlock);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	int getAverageGroundHeight(BlockSource*, BoundingBox const&);
	int getVillagerProfession(int);
	bool isOkBox(BoundingBox const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
