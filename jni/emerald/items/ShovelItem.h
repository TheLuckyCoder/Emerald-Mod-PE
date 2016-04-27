#pragma once

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/leveledit.h"

class ShovelItem : public Item
{
public:
	ShovelItem(short itemId);

public:
    ShovelItem(std::string);
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual bool canDestroySpecial(const Block*) const;
};
