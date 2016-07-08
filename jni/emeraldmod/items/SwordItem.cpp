#include "SwordItem.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"

SwordItem::SwordItem(short itemId) : Item("emeraldSword", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_sword", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int SwordItem::getAttackDamage() {
	return (Item::mItems[276]->getAttackDamage()+2.0F);
}

int SwordItem::getEnchantSlot() const{
	return 16;
}

int SwordItem::getEnchantValue() const{
	return Item::mItems[276]->getEnchantValue();
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
	if(block == Block::mWeb)
		return 20.0F;
	else
		return 1.0F;
}

bool SwordItem::canDestroyInCreative() const{
	return false;
}
