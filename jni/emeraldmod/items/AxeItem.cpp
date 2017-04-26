#include "AxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

AxeItem::AxeItem(short id) : Item("emeraldAxe", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_axe", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void AxeItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool AxeItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool AxeItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[279]->canDestroySpecial(block);
}

float AxeItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block->getMaterial() == Material::getMaterial(MaterialType::WOOD))
		return 50.0f;
	else
		return 1.0f;
}

