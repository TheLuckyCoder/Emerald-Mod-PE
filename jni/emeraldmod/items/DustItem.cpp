#include "DustItem.h"

DustItem::DustItem(short itemId) : Item("emeraldDust", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_dust", 0);
	setStackedByData(true);
}
