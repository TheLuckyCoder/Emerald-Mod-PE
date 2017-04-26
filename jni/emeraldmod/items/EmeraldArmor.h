#pragma once

#include "minecraftpe/world/item/ArmorItem.h"

class EmeraldArmor : public ArmorItem
{
public:
	EmeraldArmor(const std::string &name, short id, ArmorSlot armorSlot, const std::string &texture);
};

class EmeraldHelmet : public EmeraldArmor
{
public:
	EmeraldHelmet(short id);
};

class EmeraldChestplate : public EmeraldArmor
{
public:
	EmeraldChestplate(short id);
};

class EmeraldLeggings : public EmeraldArmor
{
public:
	EmeraldLeggings(short id);
};

class EmeraldBoots : public EmeraldArmor
{
public:
	EmeraldBoots(short id);
};

