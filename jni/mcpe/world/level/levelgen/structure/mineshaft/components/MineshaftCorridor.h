#pragma once

#include "../MineshaftPiece.h"
class CompoundTag;

class MineshaftCorridor : public MineshaftPiece
{
public:
	MineshaftData& data;

	MineshaftCorridor(MineshaftData&);
	MineshaftCorridor(MineshaftData&, int, Random&, const BoundingBox&, int);

	virtual ~MineshaftCorridor();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);

	void _placeCobWeb(BlockSource*, const BoundingBox&, Random&, float, int, int, int);
	void _placeSupport(BlockSource*, const BoundingBox&, int, int, int, int, int, Random&);
	void findCrossing(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);

	//Custom functions
    void genMineshaftCorridor(BlockSource*, Random&, const BoundingBox&);
};
tual void readAdditionalSaveData(CompoundTag&);

	//Custom functions
    void genMineshaftCorridor(BlockSource*, Random&, BoundingBox const&);
};
