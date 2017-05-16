#pragma once

#include "minecraftpe/world/item/Item.h"

class SuperPickaxeItem : public Item
{
public:
	SuperPickaxeItem(short id);
	
	virtual int getAttackDamage() { return 9; }
	virtual int getEnchantValue() const { return 18; }
	virtual int getEnchantSlot() const { return 1024; }
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
};

