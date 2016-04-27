#pragma once

#include <memory>
#include <vector>

#include "mcpe/CommonTypes.h"
#include "../../BlockSource.h"
class Block;
class BoundingBox;
class Random;
class BlockSelector;
class ChunkPos;
class Brightness;
class WeighedTreasureItem;

class StructurePiece {
public:
	BlockID id;
	unsigned char data;
	Block* block;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;
	ChunkPos const& chunk;
	int x;
	int y;
	int z;

	virtual ~StructurePiece();

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
	//void createChest(BlockSource*, BoundingBox const&, Random&, int, int, int, int, std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> const&, int);
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
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
};
