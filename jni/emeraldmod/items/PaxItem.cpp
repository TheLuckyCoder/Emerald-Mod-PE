#include "PaxItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

PaxItem::PaxItem(short id) : Item("emeraldPax", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void PaxItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool PaxItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool PaxItem::canDestroySpecial(const Block *block) const
{
	return (Item::mItems[278]->canDestroySpecial(block) || Item::mItems[279]->canDestroySpecial(block));
}

float PaxItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block->getMaterial() == Material::getMaterial(MaterialType::WOOD)
		|| block->getMaterial() == Material::getMaterial(MaterialType::STONE)
		|| block->getMaterial() == Material::getMaterial(MaterialType::METAL))
		return 50.0F;
	else
		return 1.0F;
}

