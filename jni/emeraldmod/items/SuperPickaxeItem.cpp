#include "SuperPickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/level/block/Block.h"

SuperPickaxeItem::SuperPickaxeItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2600);
	setHandEquipped();
}

void SuperPickaxeItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool SuperPickaxeItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool SuperPickaxeItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[278]->canDestroySpecial(block);
}

float SuperPickaxeItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return (block.getMaterial() == Material::getMaterial(MaterialType::STONE)
		|| block.getMaterial() == Material::getMaterial(MaterialType::METAL)) ? 80.0f : 1.0f;
}

