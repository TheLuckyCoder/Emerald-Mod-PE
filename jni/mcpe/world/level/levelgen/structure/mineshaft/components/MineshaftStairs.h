#pragma once

#include "../MineshaftPiece.h"
class CompoundTag;

class MineshaftStairs : public MineshaftPiece
{
public:
	MineshaftData& data;

	MineshaftStairs(MineshaftData&);
	MineshaftStairs(MineshaftData&, int, Random&, const BoundingBox&, int);

	virtual ~MineshaftStairs();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);

	void findStairs(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
};
