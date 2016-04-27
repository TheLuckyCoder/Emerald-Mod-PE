#include "EmeraldArmorItem.h"

ChestplateItem::ChestplateItem(short itemId) : ArmorItem("emeraldChestplate", itemId, DIAMOND, 42, ArmorSlot(1))
{
	creativeCategory = 3;
	setIcon("emerald_chestplate", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

bool ChestplateItem::isArmor() const{
	return true;
}
