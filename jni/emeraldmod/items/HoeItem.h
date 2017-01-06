#pragma once

#include "minecraftpe/world/item/Item.h"

class HoeItem : public Item
{
public:
	HoeItem(short itemId);
	
	virtual int getAttackDamage() { return 5.0f; }
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

