#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperHoeItem : public Item
{
public:
	SuperHoeItem(short id);
	
	virtual int getAttackDamage() { return 9; }
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

