#pragma once

#include "minecraftpe/world/item/Item.h"

class PickaxeItem : public Item
{
public:
	PickaxeItem(short itemId);
	
	virtual int getAttackDamage() { return 5.0f; }
	virtual int getEnchantValue() const { return 1; }
	virtual int getEnchantSlot() const { return 1024; }
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
};

