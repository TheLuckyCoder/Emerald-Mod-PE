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

void BattleAxeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(1, victim);
}

bool BattleAxeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool BattleAxeItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[279]->canDestroySpecial(block);
}

float BattleAxeItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	if (block.getMaterial() == Material::getMaterial(MaterialType::WOOD))
		return 50.0f;
	else
		return 1.0f;
}

