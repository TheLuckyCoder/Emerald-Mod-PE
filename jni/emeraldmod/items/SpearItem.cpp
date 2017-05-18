#include "SpearItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SpearItem::SpearItem(short id) : Item("emeraldSpear", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void SpearItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool SpearItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
}

