#include "SwordItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/entity/Mob.h"

SwordItem::SwordItem(short itemId) : Item("emeraldSword", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_sword", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int SwordItem::getAttackDamage()
{
	return (Item::mItems[276]->getAttackDamage() + 3);
}

int SwordItem::getEnchantValue() const
{
	return Item::mItems[276]->getEnchantValue();
}

void SwordItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool SwordItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
}

bool SwordItem::canDestroySpecial(const Block* block) const
{
	return block == Block::mWeb;
}

float SwordItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block == Block::mWeb)
		return 30.0f;
	else
		return 0.8f;
}

