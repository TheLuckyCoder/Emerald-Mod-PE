#include "EmeraldArmor.h"

EmeraldArmor::EmeraldArmor(const std::string &name, short id, ArmorSlot armorSlot, std::string texture) : ArmorItem(name, id - 256, DIAMOND, 42, armorSlot)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon(texture, 0);
	setMaxDamage(1800);
}

EmeraldHelmet::EmeraldHelmet(short id) : EmeraldArmor("emeraldHelmet", id, ArmorSlot::Helmet, "emerald_helmet") {}

EmeraldChestplate::EmeraldChestplate(short id) : EmeraldArmor("emeraldChestplate", id, ArmorSlot::Chestplate, "emerald_chestplate") {}

EmeraldLeggings::EmeraldLeggings(short id) : EmeraldArmor("emeraldLeggings", id, ArmorSlot::Leggings, "emerald_leggings") {}

EmeraldBoots::EmeraldBoots(short id) : EmeraldArmor("emeraldBoots", id, ArmorSlot::Boots, "emerald_boots") {}

