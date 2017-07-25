#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperShovelItem : public Item
{
public:
	SuperShovelItem(const std::string &name, short id);
	
	virtual int getAttackDamage() const { return 9; }
	virtual int getEnchantSlot() const { return 2048; }
	virtual int getEnchantValue() const { return 18; }
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*)const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual float getDestroySpeed(ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
};

