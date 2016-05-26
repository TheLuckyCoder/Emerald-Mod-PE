#pragma once

#include "mcpe/world/item/Item.h"

class FlintAndEmerald : public Item
{
public:
	FlintAndEmerald(short itemId);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
};
