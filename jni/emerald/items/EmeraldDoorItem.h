#pragma once

#include "mcpe/world/item/DoorItem.h"
#include "mcpe/world/material/Material.h"

class EmeraldDoorItem : public DoorItem
{
public:
	EmeraldDoorItem(short itemId, Material& material);
	
public:
	EmeraldDoorItem(std::string);
};
