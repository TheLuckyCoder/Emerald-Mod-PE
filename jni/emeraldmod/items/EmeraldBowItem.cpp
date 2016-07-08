#include "EmeraldBowItem.h"
#include "mcpe/client/renderer/texture/TextureUVCoordinateSet.h"

EmeraldBowItem::EmeraldBowItem(int itemId) : BowItem("emeraldBow", itemId)
{
	//bow_pulling_0 = ("emerald_bow_pulling", 0);
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
	//setHandEquipped();
	creativeCategory = CreativeItemCategory::TOOLS;
}
