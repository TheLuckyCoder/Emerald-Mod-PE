#pragma once

#include <vector>

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
	int x;
	int y;
	int z;

	virtual ~StructurePiece();
	virtual void createTag();
	//virtual void addChildren(); //It's to hard to demangle
	//virtual void createChest(); //It's to hard to demangle
	virtual void placeBlock(BlockSource*, FullBlock, int, int, int, const BoundingBox&);
	virtual void fillColumDown(BlockSource*, FullBlock, int, int, int, const BoundingBox&);
	virtual void generateBox(BlockSource*, const BoundingBox&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);

	void _getWorldPos(int, int, int);
	void getWorldX(int, int);
	void getWorldY(int);
	void getWorldZ(int, int);
	void getBrightness(int, int, int, BlockSource*);
	void getLocatorPosition();
	void getOrientationData(Block*, unsigned char);
	void getTorchData(unsigned char);
	FullBlock getBlock(BlockSource*, int, int, int, const BoundingBox&);
	bool isAir(BlockSource*, int, int, int, const BoundingBox&);
	void createDoor(BlockSource*, const BoundingBox&, Random&, int, int, int, int);
	void edgesLiquid(BlockSource*, const BoundingBox&);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, const BoundingBox&);
	void generateAirBox(BlockSource*, const BoundingBox&, int, int, int, int, int, int);
	void generateAirColumnUp(BlockSource*, int, int, int, const BoundingBox&);
	void generateBox(BlockSource*, const BoundingBox&, const BoundingBox&, BlockID, BlockID, bool);
	void generateBox(BlockSource*, const BoundingBox&, const BoundingBox&, bool, Random&, BlockSelector*);
	void generateBox(BlockSource*, const BoundingBox&, int, int, int, int, int, int, BlockID, unsigned char, BlockID, unsigned char, bool);
	void generateBox(BlockSource*, const BoundingBox&, int, int, int, int, int, int, bool, Random&, BlockSelector*);
	void generateMaybeBox(BlockSource*, const BoundingBox&, Random&, float, int, int, int, int, int, int, BlockID, BlockID, bool, Brightness);
	void generateUpperHalfSphere(BlockSource*, const BoundingBox&, int, int, int, int, int, int, BlockID, bool);
	bool isInChunk(const ChunkPos&);
};
