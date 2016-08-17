#pragma once

#include "minecraftpe/world/item/Item.h"

class HoeItem : public Item
{
public:
	HoeItem(short itemId);
	
	virtual int getAttackDamage() { return 5.0f; }
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

