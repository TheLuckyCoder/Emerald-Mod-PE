#pragma once

#include "minecraftpe/world/item/Item.h"

class FertilizerItem : public Item
{
public:
	FertilizerItem(const std::string &name, short id);
	
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
};

