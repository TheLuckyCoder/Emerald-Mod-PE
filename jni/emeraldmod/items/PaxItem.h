#pragma once

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"
#include "../Emerald.h"

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
