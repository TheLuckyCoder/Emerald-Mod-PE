#pragma once

#include "minecraftpe/world/item/Item.h"

class SpearItem : public Item
{
public:
	SpearItem(const std::string &name, short id);
	
	virtual int getAttackDamage() const { return 9; }
	virtual int getEnchantSlot() const { return 16; }
	virtual int getEnchantValue() const { return 18; }
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
};

