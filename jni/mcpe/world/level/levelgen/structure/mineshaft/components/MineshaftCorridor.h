#pragma once

#include "../MineshaftPiece.h"
class MineshaftData;
class BlockSource;
class BoundingBox;
class Random;
class CompoundTag;

class MineshaftCorridor : public MineshaftPiece {
public:
	MineshaftData& data;
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;
	int x;
	int y;
	int z;

	MineshaftCorridor(MineshaftData&);
	MineshaftCorridor(MineshaftData&, int, Random&, BoundingBox const&, int);

	~MineshaftCorridor();
	//void findCorridorSize(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int);
	void _placeCobWeb(BlockSource*, BoundingBox const&, Random&, float, int, int, int);
	void _placeSupport(BlockSource*, BoundingBox const&, int, int, int, int, int, Random&);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random&, BoundingBox const&);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	//Custom functions
    void genMineshaftCorridor(BlockSource*, Random&, BoundingBox const&);
};
