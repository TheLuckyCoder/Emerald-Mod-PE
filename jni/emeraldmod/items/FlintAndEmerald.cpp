#include "FlintAndEmerald.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"

FlintAndEmerald::FlintAndEmerald(short itemId) : Item("flintAndEmerald", itemId)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("flint_and_emerald", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
}

void FlintAndEmerald::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void FlintAndEmerald::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}

bool FlintAndEmerald::useOn(ItemInstance *item, Player *player, int x, int y, int z, signed char side, float xx, float yy, float zz){
	Item::mItems[259]->useOn(item, player, x, y, z, side, xx, yy, zz);
}

void FlintAndEmerald::dispense(BlockSource &region, Container &cont, int i, const Vec3 &vec, signed char ch){
	Item::mItems[259]->dispense(region, cont, i, vec, ch);
}
