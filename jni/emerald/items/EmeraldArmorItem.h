#pragma once

#include "mcpe/world/item/ArmorItem.h"

class HelmetItem : public ArmorItem
{
public:
	HelmetItem(short itemId);
public:
	HelmetItem(std::string);
	virtual bool isArmor() const;
};

class ChestplateItem : public ArmorItem
{
public:
	ChestplateItem(short itemId);
public:
	ChestplateItem(std::string);
	virtual bool isArmor() const;
};

class LeggingsItem : public ArmorItem
{
public:
	LeggingsItem(short itemId);
public:
	LeggingsItem(std::string);
	virtual bool isArmor() const;
};

class BootsItem : public ArmorItem
{
public:
	BootsItem(short itemId);
public:
	BootsItem(std::string);
	virtual bool isArmor() const;
};
