#include "EmeraldBrickBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldBrickBlock::EmeraldBrickBlock(int blockId) : Block("emeraldBrick", blockId, Material::getMaterial(MaterialType::STONE))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
}
