#pragma once

#include "../StructurePiece.h"
class MineshaftData;
class BlockSource;
class PieceWeight;
class Random;
class WeighedTreasureItem;

class MineshaftPiece : public StructurePiece {
public:
	virtual ~MineshaftPiece();
	//virtual void createChest(); //It's to hard to demangle

	bool _isSupportingBox(int, int, BlockSource*, int, int);
	void createRandomShaftPiece(MineshaftData&, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
};
