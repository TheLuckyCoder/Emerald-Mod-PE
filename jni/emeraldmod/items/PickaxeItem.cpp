#include "PickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "../EmeraldMod.h"
#include "minecraftpe/world/entity/Mob.h"

PickaxeItem::PickaxeItem(short id) : Item("emeraldPickaxe", id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_pickaxe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
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

bool PickaxeItem::canDestroySpecial(const Block* block) const
{
	return Item::mItems[278]->canDestroySpecial(block);
}

float PickaxeItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::STONE))
	|| Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::METAL)))
		return 50.0F;
	else
		return 1.0F;
}

