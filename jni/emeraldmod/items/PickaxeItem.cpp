#include "PickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "../EmeraldMod.h"
#include "minecraftpe/world/entity/Mob.h"

PickaxeItem::PickaxeItem(short itemId) : Item("emeraldPickaxe", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_pickaxe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

void PickaxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

void PickaxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool PickaxeItem::canDestroySpecial(const Block* block) const
{
	return Item::mItems[278]->canDestroySpecial(block);
}

float PickaxeItem::getDestroySpeed(ItemInstance *item, const Block *block)
{
	if (Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::STONE))
	|| Material::AreEqual(block->getMaterial(), Material::getMaterial(MaterialType::METAL)))
		return 50.0F;
	else
		return 1.0F;
}

