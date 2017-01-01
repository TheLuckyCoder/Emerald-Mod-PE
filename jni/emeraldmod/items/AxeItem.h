#pragma once

#include "minecraftpe/world/item/Item.h"

class AxeItem : public Item
{
public:
	AxeItem(short itemId);
	
	virtual int getAttackDamage() { return 5.0f; }
	virtual int getEnchantSlot() const { return 512; }
	virtual int getEnchantValue() const { return 1; }
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

