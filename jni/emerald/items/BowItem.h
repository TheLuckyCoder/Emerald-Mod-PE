#pragma once

#include "mcpe/world/item/Item.h"

class BowItem : public Item
{
public:
	BowItem(short itemId);

public:
	BowItem(std::string);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual bool use(ItemInstance&, Player&);
	virtual bool canDestroyInCreative() const;
};
