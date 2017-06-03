#include "SuperAxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

SuperAxeItem::SuperAxeItem(short id) : Item("emeraldSuperAxe", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

void SuperAxeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool SuperAxeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool SuperAxeItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[279]->canDestroySpecial(block);
}

float SuperAxeItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	if (block.getMaterial() == Material::getMaterial(MaterialType::WOOD))
		return 80.0f;
	else
		return 1.0f;
}

