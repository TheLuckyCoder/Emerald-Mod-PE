#include "RodItem.h"

RodItem::RodItem(short itemId) : Item("emeraldRod", itemId)
{
	creativeCategory = 3;
	setIcon("emerald_rod", 0);
	setStackedByData(true);
}
