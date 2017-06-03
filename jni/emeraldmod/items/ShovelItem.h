#pragma once

#include "minecraftpe/world/item/Item.h"

class ShovelItem : public Item
{
public:
	ShovelItem(short id);
	
	virtual int getAttackDamage() const { return 7; }
	virtual int getEnchantSlot() const { return 2048; }
	virtual int getEnchantValue() const { return 10; }
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual float getDestroySpeed(ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
};

