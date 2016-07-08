#pragma once

#include "mcpe/world/item/Item.h"

class PaxItem : public Item {
public:
	PaxItem(short itemId);
	virtual int getAttackDamage();
	virtual int getEnchantValue() const;
	virtual int getEnchantSlot() const;
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual bool canDestroySpecial(const Block*) const;
};
