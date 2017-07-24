#include "SwordItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/entity/Mob.h"

SwordItem::SwordItem(short id) : Item("emerald_sword", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void SwordItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(1, victim);
}

bool SwordItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

bool SwordItem::canDestroySpecial(const Block &block) const
{
	return &block == Block::mWeb;
}

float SwordItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return &block == Block::mWeb ? 20.0f : 0.8f;
}

