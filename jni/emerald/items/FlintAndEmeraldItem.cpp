#include "FlintAndEmeraldItem.h"
#include "mcpe/world/item/ItemInstance.h"

FlintAndEmeraldItem::FlintAndEmeraldItem(short itemId) : Item("flintAndEmerald", itemId)
{
	creativeCategory = 3;
	setIcon("flint_and_emerald", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
}

void FlintAndEmeraldItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void FlintAndEmeraldItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	item->hurtAndBreak(2, mob);
}

bool FlintAndEmeraldItem::useOn(ItemInstance *item, Player *player, int x, int y, int z, signed char side, float xx, float yy, float zz){
	Mob* mob;
	if(player->region.getBlockID({x, y+1, z}).id == 0)
		player->region.setBlockAndData({x, y+1, z}, {Block::mFire->blockId, 0}, 3);
	if(player->region.getBlockID({x+1, y+1, z}).id == 0 && player->region.getBlockID({x+1, y, z}).id != 0)
		player->region.setBlockAndData({x+1, y+1, z}, {Block::mFire->blockId, 0}, 3);
	if(player->region.getBlockID({x-1, y+1, z}).id == 0 && player->region.getBlockID({x-1, y, z}).id != 0)
		player->region.setBlockAndData({x-1, y+1, z}, {Block::mFire->blockId, 0}, 3);
	if(player->region.getBlockID({x, y+1, z+1}).id == 0 && player->region.getBlockID({x+1, y, z}).id != 0)
		player->region.setBlockAndData({x, y+1, z+1}, {Block::mFire->blockId, 0}, 3);
	if(player->region.getBlockID({x, y+1, z-1}).id == 0 && player->region.getBlockID({x+1, y, z}).id != 0)
		player->region.setBlockAndData({x, y+1, z-1}, {Block::mFire->blockId, 0}, 3);
	item->hurtAndBreak(1, mob);
}

void FlintAndEmeraldItem::dispense(BlockSource &region, Container &cont, int i, const Vec3 &vec, signed char ch){
	Item::mItems[259]->dispense(region, cont, i, vec, ch);
}
