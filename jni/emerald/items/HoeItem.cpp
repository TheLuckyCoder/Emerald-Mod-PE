#include "HoeItem.h"
#include "mcpe/world/item/ItemInstance.h"
//#include "mcpe/world/level/dimension/DimensionId.h"

HoeItem::HoeItem(short itemId) : Item("emeraldHoe", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_hoe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int HoeItem::getAttackDamage() {
	return 5.0F;
}

bool HoeItem::useOn(ItemInstance *item, Player *player, int x, int y, int z, signed char side, float xx, float yy, float zz){
	Item::mItems[293]->useOn(item, player, x, y, z, side, xx, yy, zz);
	//player->changeDimension(DimensionId::EMERALD);
}

void HoeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void HoeItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}
