#include "EmeraldDoorItem.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldDoorItem::EmeraldDoorItem(int itemId) : DoorItem("emeraldDoor", itemId, Material::getMaterial(MaterialType::METAL), DoorBlock::DoorType::EMERALD_DOOR){
	setMaxStackSize(16);
	creativeCategory = CreativeItemCategory::DECORATIONS;
}
