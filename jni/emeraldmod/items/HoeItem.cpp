#include "HoeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

HoeItem::HoeItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

bool HoeItem::_useOn(ItemInstance &item, Entity& entity, BlockPos pos, signed char side, float xx, float yy, float zz, ItemUseCallback *callback) const
{
	Item::mItems[293]->_useOn(item, entity, pos, side, xx, yy, zz, callback);
}

void HoeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool HoeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

