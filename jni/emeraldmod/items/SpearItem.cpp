#include "SpearItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

SpearItem::SpearItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void SpearItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(1, victim);
}

bool SpearItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(2, entity);
}

