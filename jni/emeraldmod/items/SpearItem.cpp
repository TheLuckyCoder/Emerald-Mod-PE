#include "SpearItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SpearItem::SpearItem(short id) : Item("emerald_spear", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void SpearItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(1, victim);
}

bool SpearItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

