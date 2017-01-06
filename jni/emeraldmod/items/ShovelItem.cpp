#include "ShovelItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

ShovelItem::ShovelItem(short itemId) : Item("emeraldShovel", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_shovel", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

bool ShovelItem::useOn(ItemInstance &item, Entity &entity, int x, int y, int z, signed char side, float xx, float yy, float zz)
{
	return Item::mItems[277]->useOn(item, entity, x, y, z, side, xx, yy, zz);
}

void ShovelItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool ShovelItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool ShovelItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[277]->canDestroySpecial(block);
}

float ShovelItem::getDestroySpeed(ItemInstance *item, const Block *block)
{
		if (Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::DIRT)))
		return 50.0F;
	else
		return 1.0F;
}

