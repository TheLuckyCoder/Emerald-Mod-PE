#include "EmeraldDoorItem.h"

EmeraldDoorItem::EmeraldDoorItem(short itemId, Material& material) : DoorItem("emeraldDoor", itemId, material, DoorBlock::DoorType(0)){
	setMaxStackSize(16);
}
