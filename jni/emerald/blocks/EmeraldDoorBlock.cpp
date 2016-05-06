#include "EmeraldDoorBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldDoorBlock::EmeraldDoorBlock(int blockId) : DoorBlock("emeraldDoor", blockId, Material::getMaterial(MaterialType::METAL), DoorBlock::DoorType::EMERALD_DOOR)
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
}

bool EmeraldDoorBlock::use(Player &player, const BlockPos &pos){	
	return DoorBlock::use(player, pos);
}
