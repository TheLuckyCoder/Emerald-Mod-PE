#pragma once

#include "minecraftpe/world/item/Item.h"

class ShovelItem : public Item
{
public:
	ShovelItem(short id);
	
	virtual int getAttackDamage() { return 5; }
	virtual int getEnchantSlot() const { return 2048; }
	virtual int getEnchantValue() const { return 10; }
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
};

