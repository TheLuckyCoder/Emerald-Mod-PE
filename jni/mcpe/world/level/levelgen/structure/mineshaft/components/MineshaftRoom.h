#pragma once

#include "../MineshaftPiece.h"
class CompoundTag;

class MineshaftRoom : public MineshaftPiece
{
public:
	MineshaftData& data;

	MineshaftRoom(MineshaftData&);
	MineshaftRoom(MineshaftData&, int, Random&, int, int);

	virtual ~MineshaftRoom();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
