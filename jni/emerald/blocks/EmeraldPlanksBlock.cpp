#include "EmeraldPlanksBlock.h"
#include "mcpe/CreativeItemCategory.h"
#include "mcpe/world/material/Material.h"

EmeraldPlanksBlock::EmeraldPlanksBlock(int blockId) : Block("emeraldPlanks", blockId, "emerald_planks", Material::getMaterial(MaterialType::WOOD))
{
	setDestroyTime(1.5F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
}

bool EmeraldPlanksBlock::use(Player &player, const BlockPos &pos){	
	return Block::use(player, pos);
}
