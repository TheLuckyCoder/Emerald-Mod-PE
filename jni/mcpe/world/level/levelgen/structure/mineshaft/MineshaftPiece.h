#pragma once

#include "../StructurePiece.h"
class MineshaftData;
class BlockSource;
class PieceWeight;
class Random;
class WeighedTreasureItem;

class MineshaftPiece : public StructurePiece {
public:
	Random& random;
	BlockSource* region;

	~MineshaftPiece();
	bool _isSupportingBox(int, int, BlockSource*, int, int);
	void createRandomShaftPiece(MineshaftData&, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	//void createChest(BlockSource*, BoundingBox const&, Random &, int, int, int, int, std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> const&, int);
};
