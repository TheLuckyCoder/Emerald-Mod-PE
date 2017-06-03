#pragma once

#include "minecraftpe/world/item/Item.h"

class FertilizerItem : public Item
{
public:
	FertilizerItem(short id);
	
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
};

