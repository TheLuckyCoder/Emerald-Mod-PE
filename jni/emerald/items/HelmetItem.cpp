#include "EmeraldArmorItem.h"

HelmetItem::HelmetItem(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 42, ArmorSlot(0))
{
	creativeCategory = 3;
	setIcon("emerald_helmet", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

bool HelmetItem::isArmor() const{
	return true;
}
