#include "EmeraldArmorItem.h"

LeggingsItem::LeggingsItem(short itemId) : ArmorItem("emeraldLeggings", itemId, DIAMOND, 42, ArmorSlot(2))
{
	creativeCategory = 3;
	setIcon("emerald_leggings", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

bool LeggingsItem::isArmor() const{
	return true;
}
