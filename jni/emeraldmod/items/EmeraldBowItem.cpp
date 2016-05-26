#include "EmeraldBowItem.h"

EmeraldBowItem::EmeraldBowItem(int itemId) : Item("emeraldBow", itemId)
{
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
	setHandEquipped();
	creativeCategory = CreativeItemCategory::TOOLS;
}

int EmeraldBowItem::getEnchantValue() const {
	return 1;
}

int EmeraldBowItem::getEnchantSlot() const {
	return Item::mItems[261]->getEnchantSlot();
}

int EmeraldBowItem::getAnimationFrameFor(Mob &mob) const {
	return Item::mItems[261]->getAnimationFrameFor(mob);
}

void EmeraldBowItem::releaseUsing(ItemInstance *item, Player *player, int data) {
	return Item::mItems[261]->releaseUsing(item, player, data);
}

void EmeraldBowItem::useTimeDepleted(ItemInstance *item, Level *level, Player *player) {
	return Item::mItems[261]->useTimeDepleted(item, level, player);
}

bool EmeraldBowItem::use(ItemInstance &item, Player &player) {
	Item::mItems[261]->use(item, player);
}

bool EmeraldBowItem::canDestroyInCreative() const{
	return false;
}
