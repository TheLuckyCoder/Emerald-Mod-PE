#include "SwordItem.h"
#include "mcpe/world/item/ItemInstance.h"

SwordItem::SwordItem(short itemId) : Item("emeraldSword", itemId)
{
	creativeCategory = 3;
	setIcon("emerald_sword", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

int SwordItem::getAttackDamage() {
	return 15.0F;
}

int SwordItem::getEnchantSlot() const{
	return 16;
}

int SwordItem::getEnchantValue() const{
	return 1;
}

void SwordItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(1, victim);
}

void SwordItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}

bool SwordItem::canDestroySpecial(const Block* block) const {
	return (block == Block::mWeb);
}

float SwordItem::getDestroySpeed(ItemInstance *item, Block *block) {
	if(block == Block::mWeb) {
		return 20.0F;
	} else {
		return 1.0F;
	}
}

bool SwordItem::canDestroyInCreative() const{
	return false;
}
