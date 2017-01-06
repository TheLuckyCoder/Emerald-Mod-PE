#include "EmeraldArmor.h"

EmeraldArmor::EmeraldArmor(const std::string &name, short id, ArmorSlot armorSlot, std::string texture) : ArmorItem(name, id, DIAMOND, 42, armorSlot)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon(texture, 0);
	setMaxDamage(1800);
}

EmeraldHelmet::EmeraldHelmet(short id) : ArmorItem("emeraldHelmet", id, ArmorSlot::Helmet, "emerald_helmet") {}

EmeraldChestplate::EmeraldChestplate(short id) : ArmorItem("emeraldChestplate", id, ArmorSlot::Chestplate, "emerald_chestplate") {}

EmeraldLeggings::EmeraldLeggings(short id) : ArmorItem("emeraldLeggings", id, ArmorSlot::Leggings, "emerald_leggings") {}

EmeraldBoots::EmeraldBoots(short id) : ArmorItem("emeraldBoots", id, ArmorSlot::Boots, "emerald_boots") {}
