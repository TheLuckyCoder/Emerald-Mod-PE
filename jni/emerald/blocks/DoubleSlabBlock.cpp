#include "DoubleSlabBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"
#include "../Emerald.h"

DoubleSlabBlock::DoubleSlabBlock(int blockId) : Block("emeraldDoubleSlab", blockId, "emerald_block", Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
}

bool DoubleSlabBlock::use(Player &player, const BlockPos &pos){	
	return Block::use(player, pos);
}

int DoubleSlabBlock::getResource(Random &random, int data, int fortune) {
	return Emerald::mSlab->blockId;
}

int DoubleSlabBlock::getResourceCount(Random &random, int data, int fortune) {
	return 2;
}
