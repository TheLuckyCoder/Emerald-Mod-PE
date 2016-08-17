#include "StickItem.h"

StickItem::StickItem(short itemId) : Item("emeraldStick", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_stick", 0);
}

