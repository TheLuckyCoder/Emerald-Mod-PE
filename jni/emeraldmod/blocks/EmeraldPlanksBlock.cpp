#include "EmeraldPlanksBlock.h"
#include "minecraftpe/world/material/Material.h"

EmeraldPlanksBlock::EmeraldPlanksBlock(int blockId) : Block("emeraldPlanks", blockId, Material::getMaterial(MaterialType::WOOD))
{
	setDestroyTime(1.5F);
	setExplodeable(5.0F);
	setMapColor(Color::GREEN);
	setCategory(CreativeItemCategory::Blocks);
}

