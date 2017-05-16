#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperShovelItem : public Item
{
public:
	SuperShovelItem(short id);
	
	virtual int getAttackDamage() { return 9; }
	virtual int getEnchantSlot() const { return 2048; }
	virtual int getEnchantValue() const { return 18; }
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
};

