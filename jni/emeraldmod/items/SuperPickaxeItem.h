#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperPickaxeItem : public Item
{
public:
	SuperPickaxeItem(short id);
	
	virtual int getAttackDamage() const { return 9; }
	virtual int getEnchantValue() const { return 18; }
	virtual int getEnchantSlot() const { return 1024; }
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual float getDestroySpeed(ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
};

