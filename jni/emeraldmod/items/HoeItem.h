#pragma once

#include "minecraftpe/world/item/Item.h"

class HoeItem : public Item
{
public:
	HoeItem(const std::string &name, short id);
	
	virtual int getAttackDamage() const { return 7; }
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
};

