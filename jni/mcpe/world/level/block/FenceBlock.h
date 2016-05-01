#pragma once

#include "Block.h"
class TextureUVCoordinateSet;
class ItemInstance;
class BlockPos;
class BlockSource;
class Material;
class Player;
class Random;
class AABB;

class FenceBlock : public Block {
public:
	FenceBlock(const std::string&, int, const std::string&, const Material&);

	virtual ~FenceBlock();
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual bool canBeSilkTouched() const;
	virtual void connectsTo(BlockSource&, const BlockPos&, const BlockPos&);
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual const TextureUVCoordinateSet&getTexture(signed char, int);
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
};