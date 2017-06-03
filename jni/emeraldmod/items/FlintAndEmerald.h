#pragma once

#include "minecraftpe/world/item/Item.h"

class FlintAndEmerald : public Item
{
public:
	FlintAndEmerald(short id);
	
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
};

