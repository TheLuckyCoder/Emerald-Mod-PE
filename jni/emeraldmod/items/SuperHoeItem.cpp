#include "SuperHoeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SuperHoeItem::SuperHoeItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

bool SuperHoeItem::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char side, float xx, float yy, float zz, ItemUseCallback *callback) const
{
	Item::mItems[293]->_useOn(item, entity, pos, side, xx, yy, zz, callback);
}

void SuperHoeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool SuperHoeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

