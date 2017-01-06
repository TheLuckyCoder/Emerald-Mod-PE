#include "AxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "../EmeraldMod.h"

AxeItem::AxeItem(short itemId) : Item("emeraldAxe", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_axe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

void AxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool AxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool AxeItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[279]->canDestroySpecial(block);
}

float AxeItem::getDestroySpeed(ItemInstance *item, const Block *block)
{
	if (Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::WOOD)))
		return 50.0F;
	else
		return 1.0F;
}

