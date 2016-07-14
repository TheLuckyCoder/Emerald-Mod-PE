#include "DustItem.h"

DustItem::DustItem(short itemId) : Item("emeraldDust", itemId)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("emerald_dust", 0);
	setStackedByData(true);
}
