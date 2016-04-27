#include "EmeraldArmorItem.h"

HelmetItem::HelmetItem(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 42, ArmorSlot(0))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_helmet", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
}

bool HelmetItem::isArmor() const{
	return true;
}
