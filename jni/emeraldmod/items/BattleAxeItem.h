#pragma once

#include "minecraftpe/world/item/Item.h"

class BattleAxeItem : public Item
{
public:
	BattleAxeItem(short id);
	
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const { return 512; }
	virtual int getEnchantValue() const { return 10; }
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual bool canDestroySpecial(const Block*) const;
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

