#include "FlintAndEmerald.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/entity/Mob.h"

FlintAndEmerald::FlintAndEmerald(short id) : Item("flint_and_emerald", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

void FlintAndEmerald::hurtEnemy(ItemInstance&, Mob*, Mob *victim) const
{
	victim->setOnFire(1000);
}

bool FlintAndEmerald::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char side, float xx, float yy, float zz) const
{
	Item::mItems[259]->_useOn(item, entity, pos, side, xx, yy, zz);
}

void FlintAndEmerald::dispense(BlockSource &region, Container &cont, int i, const Vec3 &pos, signed char side) const
{
	Item::mItems[259]->dispense(region, cont, i, pos, side);
}

