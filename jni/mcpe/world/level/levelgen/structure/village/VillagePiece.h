#pragma once

#include "../StartPiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class FullBlock;
class PieceWeight;

class VillagePiece : public StructurePiece {
public:
	VillagePiece();
	VillagePiece(StartPiece*, int);

	virtual ~VillagePiece();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void spawnVillagers(BlockSource*, BoundingBox const&, int, int, int, int);
	bool biomeBlock(FullBlock);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	int getAverageGroundHeight(BlockSource*, BoundingBox const&);
	int getVillagerProfession(int);
	bool isOkBox(BoundingBox const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void findAndCreatePieceFactory(StartPiece*, PieceWeight&, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void generateAndAddPiece(StartPiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void generateAndAddRoadPiece(StartPiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void generateHouseNorthernLeft(StartPiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random &, int, int);
	void generateHouseNorthernRight(StartPiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random &, int, int);
	void generatePieceFromSmallDoor(StartPiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random &, int, int, int, int, int);
};
