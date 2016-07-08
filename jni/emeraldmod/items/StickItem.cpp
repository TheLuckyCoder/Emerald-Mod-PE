#include "StickItem.h"

StickItem::StickItem(short itemId) : Item("emeraldStick", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_rod", 0);
	setStackedByData(true);
}
