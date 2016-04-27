#pragma once

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"
#include "mcpe/leveledit.h"

class SuperSwordItem : public Item {
public:
	SuperSwordItem(short itemId);

public:
    SuperSwordItem(std::string);
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual bool canDestroySpecial(const Block*) const;
	virtual bool canDestroyInCreative() const;
};
