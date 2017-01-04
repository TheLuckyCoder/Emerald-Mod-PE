#pragma once

#include "Item.h"

class BowItem : public Item
{
public:
	TextureUVCoordinateSet& bow_pulling_0;
	char filler1[20];
	TextureUVCoordinateSet& bow_pulling_1;
	char filler2[20];
	TextureUVCoordinateSet& bow_pulling_2;
	char filler3[20];	

	BowItem(const std::string&, int);

	virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool use(ItemInstance&, Player&);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};

