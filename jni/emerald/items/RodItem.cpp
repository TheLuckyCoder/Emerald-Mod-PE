#include "RodItem.h"

RodItem::RodItem(short itemId) : Item("emeraldRod", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_rod", 0);
	setStackedByData(true);
}
