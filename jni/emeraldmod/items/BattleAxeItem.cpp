#include "BattleAxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

BattleAxeItem::BattleAxeItem(short id) : Item("emeraldBattleAxe", id - 256)
{
	mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

int BattleAxeItem::getAttackDamage()
{
	return (Item::mItems[276]->getAttackDamage() + 3);
}

void BattleAxeItem::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

bool BattleAxeItem::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(1, entity);
}

bool BattleAxeItem::canDestroySpecial(const Block *block) const
{
	return Item::mItems[279]->canDestroySpecial(block);
}

float BattleAxeItem::getDestroySpeed(ItemInstance*, const Block *block)
{
	if (block->getMaterial() == Material::getMaterial(MaterialType::WOOD))
		return 50.0f;
	else
		return 1.0f;
}

