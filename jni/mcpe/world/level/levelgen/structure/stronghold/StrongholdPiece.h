#pragma once

#include"../StructurePiece.h"
class CompoundTag;
class SmallDoorType;

class StrongholdPiece : public StructurePiece
{
public:
	virtual ~StrongholdPiece();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	void randomSmallDoor(Random&);
	void generateSmallDoor(BlockSource*, Random&, BoundingBox const&, SmallDoorType, int, int, int);
};