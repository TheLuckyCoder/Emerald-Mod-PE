#include "EmeraldArmor.h"

EmeraldHelmet::EmeraldHelmet(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 76, ArmorSlot(0))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_helmet", 0);
	setMaxDamage(1800);
}

EmeraldChestplate::EmeraldChestplate(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 76, ArmorSlot(1))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_chestplate", 0);
	setMaxDamage(1800);
}

EmeraldLeggings::EmeraldLeggings(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 76, ArmorSlot(2))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_leggings", 0);
	setMaxDamage(1800);
}

EmeraldBoots::EmeraldBoots(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 76, ArmorSlot(3))
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_boots", 0);
	setMaxDamage(1800);
}
