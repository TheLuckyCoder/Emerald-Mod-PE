#include "SuperHoeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SuperHoeItem::SuperHoeItem(short id) : Item("emeraldSuperHoe", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

bool SuperHoeItem::useOn(ItemInstance &item, Entity& entity, int x, int y, int z, signed char side, float xx, float yy, float zz)
{
	Item::mItems[293]->useOn(item, entity, x, y, z, side, xx, yy, zz);
}

void SuperHoeItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool SuperHoeItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
}

