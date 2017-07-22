#include "SuperShovelItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

SuperShovelItem::SuperShovelItem(short id) : Item("emerald_shovel_super", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

bool SuperShovelItem::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char side, float xx, float yy, float zz) const
{	
	return Item::mItems[277]->_useOn(item, entity, pos, side, xx, yy, zz);
}

void SuperShovelItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool SuperShovelItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool SuperShovelItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[277]->canDestroySpecial(block);
}

float SuperShovelItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return block.getMaterial() == Material::getMaterial(MaterialType::DIRT) ? 80.0f : 1.0f;
}

