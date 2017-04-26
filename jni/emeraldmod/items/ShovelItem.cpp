#include "ShovelItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

ShovelItem::ShovelItem(short id) : Item("emeraldShovel", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_shovel", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

bool ShovelItem::useOn(ItemInstance &item, Entity &entity, int x, int y, int z, signed char side, float xx, float yy, float zz)
{
	return Item::mItems[277]->useOn(item, entity, x, y, z, side, xx, yy, zz);
}

void ShovelItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool ShovelItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool ShovelItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[277]->canDestroySpecial(block);
}

float ShovelItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block->getMaterial() == Material::getMaterial(MaterialType::DIRT))
		return 50.0f;
	else
		return 1.0f;
}

