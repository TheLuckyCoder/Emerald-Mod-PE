#include "HoeItem.h"
#include "mcpe/world/item/ItemInstance.h"

HoeItem::HoeItem(short itemId) : Item("emeraldHoe", itemId)
{
	creativeCategory = 3;
	setIcon("emerald_hoe", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

int HoeItem::getAttackDamage() {
	return 5.0F;
}

bool HoeItem::useOn(ItemInstance *item, Player *player, int x, int y, int z, signed char side, float xx, float zz, float yy){
	Mob* mob;
	if(player->region.getMaterial({x, y, z}).isType(MaterialType::DIRT)) {
		player->region.setBlockAndData({x, y, z}, {Block::mFarmland->blockId, 0}, 3);
		item->hurtAndBreak(1, mob);
	}
}

void HoeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void HoeItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}
