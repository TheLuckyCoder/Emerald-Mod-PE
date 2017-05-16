#pragma once

#include "minecraftpe/world/item/Item.h"

class PaxItem : public Item
{
public:
	PaxItem(short id);
	
	virtual int getAttackDamage() { return 7; }
	virtual int getEnchantValue() const { return 10; }
	virtual int getEnchantSlot() const { return 1024; }
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
};

