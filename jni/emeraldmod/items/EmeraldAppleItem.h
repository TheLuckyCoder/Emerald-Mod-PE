#pragma once

#include "mcpe/world/item/Item.h"

class EmeraldAppleItem : public Item
{
public:
	EmeraldAppleItem(short itemId);
	//void init(Json::Value&);
	virtual bool isFoil(const ItemInstance*) const;
};
