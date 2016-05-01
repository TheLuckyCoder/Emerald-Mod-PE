#include "EmeraldDoorItem.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldDoorItem::EmeraldDoorItem(short itemId) : DoorItem("emeraldDoor", itemId, Material::getMaterial(MaterialType::METAL), DoorBlock::DoorType(0)){
	setMaxStackSize(16);
	creativeCategory = CreativeItemCategory::DECORATIONS;
}
