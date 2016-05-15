#pragma once

#include"../StructurePiece.h"
class CompoundTag;

class NetherBridgePiece : public StructurePiece
{
public:
	NetherBridgePiece();
	NetherBridgePiece(int);

	virtual ~NetherBridgePiece();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	bool isOkBox(BoundingBox);
	void generateLightPostFacingUp(BlockSource*, Random&, const BoundingBox&, int, int, int);
	void generateLightPostFacingRight(BlockSource*, Random&, const BoundingBox&, int, int, int);
	void generateLightPostFacingLeft(BlockSource*, Random&, const BoundingBox&, int, int, int);
	void generateLightPostFacingDown(BlockSource*, Random&, const BoundingBox&, int, int, int);
	void generateLightPost(BlockSource*, Random&, BoundingBox const&, int, int, int, int, int);
	void fillWeighedTreasureList(std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>>&);
};
st(std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> &);
};