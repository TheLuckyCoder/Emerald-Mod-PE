#pragma once

#include "../MineshaftPiece.h"
class CompoundTag;

class MineshaftCrossing : public MineshaftPiece
{
public:
	MineshaftData& data;

	MineshaftCrossing(MineshaftData&);
	MineshaftCrossing(MineshaftData&, int, Random&, const BoundingBox&, int);

	virtual ~MineshaftCrossing();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);

	void _placeSupportPillar(BlockSource*, const BoundingBox&, int, int, int, int);
	void findCrossing(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
};
