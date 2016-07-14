#include "SuperSwordItem.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"

SuperSwordItem::SuperSwordItem(short itemId) : Item("emeraldSuperSword", itemId)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("emerald_super_sword", 0);
	setMaxStackSize(1);
	setMaxDamage(2100);
	setHandEquipped();
}

int SuperSwordItem::getAttackDamage() {
	return (Item::mItems[276]->getAttackDamage()+4.0F);
}

int SuperSwordItem::getEnchantSlot() const{
	return 16;
}

int SuperSwordItem::getEnchantValue() const{
	return 1;
}

void SuperSwordItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(1, victim);
}

void SuperSwordItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}

bool SuperSwordItem::canDestroySpecial(const Block* block) const {
	return (block == Block::mWeb);
}

float SuperSwordItem::getDestroySpeed(ItemInstance *item, Block *block) {
	if(block == Block::mWeb) {
		return 20.0F;
	} else {
		return 1.0F;
	}
}

bool SuperSwordItem::canDestroyInCreative() const{
	return false;
}
