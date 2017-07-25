#include "EmeraldArmor.h"

EmeraldHelmet::EmeraldHelmet(const std::string &name, short id) : ArmorItem(name, id, DIAMOND, 42, ArmorSlot::HELMET)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(2000);
}

EmeraldChestplate::EmeraldChestplate(const std::string &name, short id) : ArmorItem(name, id, DIAMOND, 42, ArmorSlot::CHESTPLATE)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(2000);
}

EmeraldLeggings::EmeraldLeggings(const std::string &name, short id) : ArmorItem(name, id, DIAMOND, 42, ArmorSlot::LEGGINGS)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(2000);
}

EmeraldBoots::EmeraldBoots(const std::string &name, short id) : ArmorItem(name, id, DIAMOND, 42, ArmorSlot::BOOTS)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(2000);
}
