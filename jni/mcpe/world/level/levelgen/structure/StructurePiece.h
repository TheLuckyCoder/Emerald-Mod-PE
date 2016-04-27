#pragma once

#include <vector>

#include "../../../../CommonTypes.h"

class Block;
class BlockID;
class BlockSource;
class BoundingBox;
class FullBlock;
class Random;
class BlockSelector;
class ChunkPos;
class Brightness;
class WeighedTreasureItem;

class StructurePiece {
public:
	BlockID id; // 9
	unsigned char data; // 10

	virtual ~StructurePiece();
	void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	void _getWorldPos(int, int, int);
	void getWorldX(int, int);
	void getWorldY(int);
	void getWorldZ(int, int);
	void createTag();
	void getBrightness(int, int, int, BlockSource*);
	void getLocatorPosition();
	void getOrientationData(Block*, unsigned char);
	void getTorchData(unsigned char);
	FullBlock getBlock(BlockSource*, int, int, int, BoundingBox const&);
	bool isAir(BlockSource*, int, int, int, BoundingBox const&);
	void createChest(BlockSource*, BoundingBox const&, Random&, int, int, int, int, std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> const&, int);
	void createDoor(BlockSource*, BoundingBox const&, Random&, int, int, int, int);
	void edgesLiquid(BlockSource*, BoundingBox const&);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateAirBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int);
	void generateAirColumnUp(BlockSource*, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, BoundingBox const&, BlockID, BlockID, bool);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	void generateBox(BlockSource*, BoundingBox const&, BoundingBox const&, bool, Random&, BlockSelector*);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, BlockID, unsigned char, BlockID, unsigned char, bool);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, bool, Random&, BlockSelector*);
	void generateMaybeBox(BlockSource*, BoundingBox const&, Random&, float, int, int, int, int, int, int, BlockID, BlockID, bool, Brightness);
	void generateUpperHalfSphere(BlockSource*, BoundingBox const&, int, int, int, int, int, int, BlockID, bool);
	bool isInChunk(ChunkPos const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
};
