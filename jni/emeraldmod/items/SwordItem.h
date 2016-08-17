#pragma once

#include "minecraftpe/world/item/Item.h"

class SwordItem : public Item
{
public:
	SwordItem(short itemId);
	
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const { return 16; }
	virtual int getEnchantValue() const;
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual bool canDestroySpecial(const Block*) const;
	virtual bool canDestroyInCreative() const { return false; }
};

