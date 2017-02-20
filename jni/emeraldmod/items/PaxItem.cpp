#include "PaxItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "../EmeraldMod.h"

PaxItem::PaxItem(short itemId) : Item("emeraldPax", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_pax", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
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
		if (Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::WOOD))
			|| Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::STONE))
			|| Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::METAL)))
		return 50.0F;
	else
		return 1.0F;
}

