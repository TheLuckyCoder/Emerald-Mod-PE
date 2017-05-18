#pragma once

#include "minecraftpe/world/item/Item.h"

class SpearItem : public Item
{
public:
	SpearItem(short id);
	
	virtual int getAttackDamage() { return 9; }
	virtual int getEnchantSlot() const { return 16; }
	virtual int getEnchantValue() const { return 18; }
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
};

