#pragma once

#include "Item.h"

class BowItem : public Item
{
private:
	int _getLaunchPower(int) const;
public:
	void**vtable;
	/*TextureUVCoordinateSet& bow_pulling_0; // 108
	char filler1[24]; // 112
	TextureUVCoordinateSet& bow_pulling_1; // 136
	char filler2[24]; // 140
	TextureUVCoordinateSet& bow_pulling_2; // 164*/

	BowItem(const std::string&, int);

	virtual ~BowItem();
	virtual Item* setIcon(const std::string&, int);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool use(ItemInstance&, Player&);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual CameraItemComponent releaseUsing(ItemInstance*, Player*, int);
	//virtual void hurtEnemey(ItemInstance*, Mob*, Mob*);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};

