#include "ShovelItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

ShovelItem::ShovelItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

bool ShovelItem::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char side, float xx, float yy, float zz) const
{
	return Item::mItems[277]->_useOn(item, entity, pos, side, xx, yy, zz);
}

void ShovelItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool ShovelItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool ShovelItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[277]->canDestroySpecial(block);
}

float ShovelItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return block.getMaterial() == Material::getMaterial(MaterialType::DIRT) ? 50.0f : 1.0f;
}

