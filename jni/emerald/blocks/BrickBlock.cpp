#include "BrickBlock.h"
#include "mcpe/world/material/Material.h"

BrickBlock::BrickBlock(int blockId) : Block("emeraldBrick", blockId, "emerald_brick", Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = 1;
}

bool BrickBlock::use(Player& player, const BlockPos& pos){	
	return Block::use(player, pos);
}
