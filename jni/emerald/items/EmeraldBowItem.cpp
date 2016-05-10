#include "EmeraldBowItem.h"

EmeraldBowItem::EmeraldBowItem(int itemId) : BowItem("emeraldBow", itemId)
{
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
	setHandEquipped();
	creativeCategory = CreativeItemCategory::TOOLS;
}
