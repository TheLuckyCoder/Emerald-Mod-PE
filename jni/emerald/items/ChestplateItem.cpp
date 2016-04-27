#include "EmeraldArmorItem.h"

ChestplateItem::ChestplateItem(short itemId) : ArmorItem("emeraldChestplate", itemId, DIAMOND, 42, ArmorSlot(1))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_chestplate", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
}

bool ChestplateItem::isArmor() const{
	return true;
}
