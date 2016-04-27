#include "EmeraldArmorItem.h"

BootsItem::BootsItem(short itemId) : ArmorItem("emeraldBoots", itemId, DIAMOND, 42, ArmorSlot(3))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_boots", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
}

bool BootsItem::isArmor() const{
	return true;
}
