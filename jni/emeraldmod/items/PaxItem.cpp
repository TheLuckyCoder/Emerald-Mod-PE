#include "PaxItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"
#include "minecraftpe/world/block/Block.h"

PaxItem::PaxItem(const std::string &name, short id) : Item(name, id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

void PaxItem::hurtEnemy(ItemInstance &item, Mob*, Mob *victim) const
{
	item.hurtAndBreak(2, victim);
}

bool PaxItem::mineBlock(ItemInstance &item, BlockID, int, int, int, Entity *entity) const
{
	item.hurtAndBreak(1, entity);
}

bool PaxItem::canDestroySpecial(const Block &block) const
{
	return Item::mItems[278]->canDestroySpecial(block) || Item::mItems[279]->canDestroySpecial(block);
}

float PaxItem::getDestroySpeed(ItemInstance&, const Block &block) const
{
	return (block.getMaterial() == Material::getMaterial(MaterialType::WOOD)
		|| block.getMaterial() == Material::getMaterial(MaterialType::STONE)
		|| block.getMaterial() == Material::getMaterial(MaterialType::METAL)) ? 50.0F : 1.0F;
}

