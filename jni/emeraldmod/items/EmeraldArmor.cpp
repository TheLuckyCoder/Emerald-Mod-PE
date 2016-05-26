#include "EmeraldArmor.h"

EmeraldHelmet::EmeraldHelmet(short itemId) : ArmorItem("emeraldHelmet", itemId, DIAMOND, 42, ArmorSlot::HELMET)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_helmet", 0);
	setMaxDamage(1800);
}

EmeraldChestplate::EmeraldChestplate(short itemId) : ArmorItem("emeraldChestplate", itemId, DIAMOND, 42, ArmorSlot::CHESTPLATE)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_chestplate", 0);
	setMaxDamage(1800);
}

EmeraldLeggings::EmeraldLeggings(short itemId) : ArmorItem("emeraldLeggings", itemId, DIAMOND, 42, ArmorSlot::LEGGINGS)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_leggings", 0);
	setMaxDamage(1800);
}

EmeraldBoots::EmeraldBoots(short itemId) : ArmorItem("emeraldBoots", itemId, DIAMOND, 42, ArmorSlot::BOOTS)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_boots", 0);
	setMaxDamage(1800);
}
