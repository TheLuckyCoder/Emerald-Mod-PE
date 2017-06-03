#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperAxeItem : public Item
{
public:
	SuperAxeItem(short id);
	
	virtual int getAttackDamage() const { return 9; }
	virtual int getEnchantSlot() const { return 512; }
	virtual int getEnchantValue() const { return 18; }
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual float getDestroySpeed(ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
};

