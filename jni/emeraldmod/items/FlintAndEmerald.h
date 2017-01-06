#pragma once

#include "minecraftpe/world/item/Item.h"

class FlintAndEmerald : public Item
{
public:
	FlintAndEmerald(short itemId);
	
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
};

