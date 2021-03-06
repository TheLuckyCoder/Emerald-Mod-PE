#include "PickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/block/Block.h"

PickaxeItem::PickaxeItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void PickaxeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool PickaxeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool PickaxeItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[278]->canDestroySpecial(block);
}

float PickaxeItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return (block.getMaterial() == Material::getMaterial(MaterialType::STONE)
		|| block.getMaterial() == Material::getMaterial(MaterialType::METAL)) ? 50.0f : 1.0f;
}

