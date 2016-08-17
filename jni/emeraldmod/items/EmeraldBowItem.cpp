#include "EmeraldBowItem.h"

EmeraldBowItem::EmeraldBowItem(int itemId) : BowItem("emeraldBow", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
}

