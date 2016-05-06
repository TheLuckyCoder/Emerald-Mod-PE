#include "EmeraldSlabBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldSlabBlock::EmeraldSlabBlock(int blockId) : SlabBlock("emeraldSlab", blockId, "emerald_block", false, Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
	emeraldTex = getTextureUVCoordinateSet("emerald_block", 0);
}

bool EmeraldSlabBlock::use(Player &player, const BlockPos &pos){
	return SlabBlock::use(player, pos);
}

const TextureUVCoordinateSet& EmeraldSlabBlock::getTexture(signed char data) {
	return emeraldTex;
}
