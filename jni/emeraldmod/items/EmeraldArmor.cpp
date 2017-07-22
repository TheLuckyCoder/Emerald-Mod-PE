#include "EmeraldArmor.h"

EmeraldArmor::EmeraldArmor(const std::string &name, short id, ArmorSlot armorSlot, const std::string& texture) : ArmorItem(name, id - 256, DIAMOND, 42, armorSlot)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon(texture, 0);
	setMaxDamage(2000);
}

EmeraldHelmet::EmeraldHelmet(short id) : EmeraldArmor("emerald_helmet", id, ArmorSlot::Helmet, "emerald_helmet") {}

EmeraldChestplate::EmeraldChestplate(short id) : EmeraldArmor("emerald_chestplate", id, ArmorSlot::Chestplate, "emerald_chestplate") {}

EmeraldLeggings::EmeraldLeggings(short id) : EmeraldArmor("emerald_leggings", id, ArmorSlot::Leggings, "emerald_leggings") {}

EmeraldBoots::EmeraldBoots(short id) : EmeraldArmor("emerald_boots", id, ArmorSlot::Boots, "emerald_boots") {}

