#include "SuperHoeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SuperHoeItem::SuperHoeItem(short id) : Item("emerald_hoe_super", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

bool SuperHoeItem::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char side, float xx, float yy, float zz) const
{
	Item::mItems[293]->_useOn(item, entity, pos, side, xx, yy, zz);
}

void SuperHoeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool SuperHoeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

