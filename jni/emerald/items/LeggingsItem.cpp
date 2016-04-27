#include "EmeraldArmorItem.h"

LeggingsItem::LeggingsItem(short itemId) : ArmorItem("emeraldLeggings", itemId, DIAMOND, 42, ArmorSlot(2))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_leggings", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
}

bool LeggingsItem::isArmor() const{
	return true;
}
