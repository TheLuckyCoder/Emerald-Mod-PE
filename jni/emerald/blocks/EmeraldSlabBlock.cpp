#include "EmeraldSlabBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldSlabBlock::EmeraldSlabBlock(int blockId) : SlabBlock("emeraldSlab", blockId, "emerald_block", false, Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	setSolid(false);
	//setVisualShape({0.0F, 0.0F, 0.0F}, {1.0F, 0.5F, 1.0F});
	creativeCategory = CreativeItemCategory::BLOCKS;
}

bool EmeraldSlabBlock::use(Player &player, const BlockPos &pos){	
	return SlabBlock::use(player, pos);
}
