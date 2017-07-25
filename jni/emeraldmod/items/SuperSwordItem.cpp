#include "SuperSwordItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

SuperSwordItem::SuperSwordItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

void SuperSwordItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(1, victim);
}

bool SuperSwordItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

bool SuperSwordItem::canDestroySpecial(const Block &block) const
{
	return &block == Block::mWeb;
}

float SuperSwordItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return &block == Block::mWeb ? 30.0f : 0.8f;
}

