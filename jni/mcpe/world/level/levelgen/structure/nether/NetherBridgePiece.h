#pragma once

#include"../StructurePiece.h"
class BoundingBox;
class BlockSource;
class Random;
class CompoundTag;
class WeighedTreasureItem;

class NetherBridgePiece : public StructurePiece {
public:
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;
	int x;
	int y;
	int z;

	NetherBridgePiece();
	NetherBridgePiece(int);

	~NetherBridgePiece();
	bool isOkBox(BoundingBox);
	void generateLightPostFacingUp(BlockSource*, Random&, BoundingBox const&, int, int, int);
	void generateLightPostFacingRight(BlockSource*, Random&, BoundingBox const&, int, int, int);
	void generateLightPostFacingLeft(BlockSource*, Random&, BoundingBox const&, int, int, int);
	void generateLightPostFacingDown(BlockSource*, Random&, BoundingBox const&, int, int, int);
	void generateLightPost(BlockSource*, Random&, BoundingBox const&, int, int, int, int, int);
	void fillWeighedTreasureList(std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> &);

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};