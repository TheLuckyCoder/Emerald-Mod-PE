#include "EmeraldDoorItem.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldDoorItem::EmeraldDoorItem(int itemId) : DoorItem("emeraldDoor", itemId, Material::getMaterial(MaterialType::METAL), DoorBlock::DoorType::DOOR_EMERALD){
	setMaxStackSize(16);
	creativeCategory = CreativeItemCategory::DECORATIONS;
}
