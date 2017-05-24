#pragma once

#include "minecraftpe/world/item/Item.h"

class FertilizerItem : public Item
{
public:
	FertilizerItem(short id);
	
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};

