#include "EmeraldSlabBlock.h"
#include "minecraftpe/world/material/Material.h"

EmeraldSlabBlock::EmeraldSlabBlock(int blockId) : SlabBlock("emeraldSlab", blockId, false, Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	setCategory(CreativeItemCategory::Blocks);
}

