#pragma once

#include "mcpe/world/item/ArmorItem.h"

class HelmetItem : public ArmorItem
{
public:
	HelmetItem(short itemId);
	virtual bool isArmor() const;
};

class ChestplateItem : public ArmorItem
{
public:
	ChestplateItem(short itemId);
	virtual bool isArmor() const;
};

class LeggingsItem : public ArmorItem
{
public:
	LeggingsItem(short itemId);
	virtual bool isArmor() const;
};

class BootsItem : public ArmorItem
{
public:
	BootsItem(short itemId);
	virtual bool isArmor() const;
};
