#include "DustItem.h"

DustItem::DustItem(short itemId) : Item("emeraldDust", itemId)
{
	creativeCategory = 3;
	setIcon("emerald_dust", 0);
	setStackedByData(true);
}
