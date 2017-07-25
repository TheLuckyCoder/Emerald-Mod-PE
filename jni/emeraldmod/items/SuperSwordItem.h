#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperSwordItem : public Item
{
public:
	SuperSwordItem(const std::string &name, short id);
	
	virtual int getAttackDamage() const { return 16; }
	virtual int getEnchantSlot() const { return 16; }
	virtual int getEnchantValue() const { return 18; }
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual float getDestroySpeed(ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
	virtual bool canDestroyInCreative() const { return false; }
};

