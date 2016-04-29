#include "BowItem.h"

BowItem::BowItem(short itemId) : Item("emeraldBow", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_bow_standby", 0);
	setMaxDamage(1800);
}

int BowItem::getEnchantValue() const {
	return 1;
}

int BowItem::getEnchantSlot() const {
	return Item::mItems[261]->getEnchantSlot();
}

int BowItem::getAnimationFrameFor(Mob &mob) const {
	return Item::mItems[261]->getAnimationFrameFor(mob);
}

void BowItem::releaseUsing(ItemInstance *item, Player *player, int data) {
	return Item::mItems[261]->releaseUsing(item, player, data);
}

void BowItem::useTimeDepleted(ItemInstance *item, Level *level, Player *player) {
	return Item::mItems[261]->useTimeDepleted(item, level, player);
}

bool BowItem::use(ItemInstance &item, Player &player) {
	Item::mItems[261]->use(item, player);
}

bool BowItem::canDestroyInCreative() const{
	return false;
}
