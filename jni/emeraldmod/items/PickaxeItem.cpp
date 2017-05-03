#include "PickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "../Emerald.h"

PickaxeItem::PickaxeItem(short id) : Item("emeraldPickaxe", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void PickaxeItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool PickaxeItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool PickaxeItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[278]->canDestroySpecial(block);
}

float PickaxeItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block->getMaterial() == Material::getMaterial(MaterialType::STONE)
		|| block->getMaterial() == Material::getMaterial(MaterialType::METAL))
		return 50.0f;
	else
		return 1.0f;
}

