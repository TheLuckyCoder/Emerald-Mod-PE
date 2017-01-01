#pragma once

#include "minecraftpe/world/item/Item.h"

class FlintAndEmerald : public Item
{
public:
	FlintAndEmerald(short itemId);
	
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
};

