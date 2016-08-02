#include "StickItem.h"

StickItem::StickItem(short itemId) : Item("emeraldStick", itemId)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("emerald_stick", 0);
}
