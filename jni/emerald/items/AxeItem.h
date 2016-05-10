#pragma once

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"
#include "../Emerald.h"

class AxeItem : public Item
{
public:
	AxeItem(short itemId);
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
