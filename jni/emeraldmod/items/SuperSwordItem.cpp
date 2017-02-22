#include "SuperSwordItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

SuperSwordItem::SuperSwordItem(short id) : Item("emeraldSuperSword", id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_super_sword", 0);
	setMaxStackSize(1);
	setMaxDamage(2400);
	setHandEquipped();
}

int SuperSwordItem::getAttackDamage()
{
	return (Item::mItems[276]->getAttackDamage() + 5);
}

int SuperSwordItem::getEnchantValue() const
{
	return Item::mItems[276]->getEnchantValue();
}

void SuperSwordItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool SuperSwordItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Entity *entity)
{
	item->hurtAndBreak(2, entity);
}

bool SuperSwordItem::canDestroySpecial(const Block* block) const
{
	return (block == Block::mWeb);
}

float SuperSwordItem::getDestroySpeed(ItemInstance *item, const Block *block) {
	if(block == Block::mWeb)
		return 20.0f;
	else
		return 0.8f;
}

