#include "EmeraldBowItem.h"

#include "minecraftpe/client/render/TextureUVCoordinateSet.h"

EmeraldBowItem::EmeraldBowItem(short id) : BowItem("emeraldBow", id)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
	bow_pulling_0 = getTextureUVCoordinateSet("emerald_bow_pulling", 0);
	bow_pulling_1 = getTextureUVCoordinateSet("emerald_bow_pulling", 1);
	bow_pulling_2 = getTextureUVCoordinateSet("emerald_bow_pulling", 2);
}

