#include "EmeraldArmorItem.h"

BootsItem::BootsItem(short itemId) : ArmorItem("emeraldBoots", itemId, DIAMOND, 42, ArmorSlot(3))
{
	creativeCategory = 3;
	setIcon("emerald_boots", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

bool BootsItem::isArmor() const{
	return true;
}
