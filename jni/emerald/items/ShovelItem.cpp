#include "ShovelItem.h"
#include "mcpe/world/item/ItemInstance.h"

ShovelItem::ShovelItem(short itemId) : Item("emeraldShovel", itemId)
{
	creativeCategory = 3;
	setIcon("emerald_shovel", 0);
	setMaxStackSize(1);
	setMaxDamage(2000);
	setHandEquipped();
}

int ShovelItem::getAttackDamage() {
	return 5.0F;
}

int ShovelItem::getEnchantSlot() const{
	return 2048;
}

int ShovelItem::getEnchantValue() const{
	return 1;
}

bool ShovelItem::useOn(ItemInstance *item, Player *player, int x, int y, int z, signed char side, float xx, float yy, float zz){
	Mob* mob;
	if(player->region.getBlockID({x, y, z}).id == Block::mGrass->blockId){
		player->region.setBlock({x, y, z}, Block::mGrassPathBlock->blockId, 3);
		item->hurtAndBreak(1, mob);
	}
}

void ShovelItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void ShovelItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	if(blockid == Block::mGrass->blockId
	||blockid == Block::mDirt->blockId
	||blockid == Block::mSand->blockId
	||blockid == Block::mGravel->blockId
	||blockid == Block::mFarmland->blockId
	||blockid == Block::mSnow->blockId
	||blockid == Block::mSoulSand->blockId
	||blockid == Block::mGrassPathBlock->blockId
	||blockid == Block::mPodzol->blockId
	||blockid == Block::mMycelium->blockId
	||blockid == Block::mTopSnow->blockId
	||blockid == Block::mGravel->blockId){
		item->hurtAndBreak(1, mob);
	} else {
		item->hurtAndBreak(2, mob);
	}
}

bool ShovelItem::canDestroySpecial(const Block *block) const {
	return (block == Block::mTopSnow ||block == Block::mSnow);
}

float ShovelItem::getDestroySpeed(ItemInstance *item, Block *block) {
	if(block == Block::mGrass
	||block == Block::mDirt
	||block == Block::mSand
	||block == Block::mGravel
	||block == Block::mFarmland
	||block == Block::mSnow
	||block == Block::mSoulSand
	||block == Block::mGrassPathBlock
	||block == Block::mPodzol
	||block == Block::mMycelium
	||block == Block::mTopSnow
	||block == Block::mGravel) {
		return 50.0F;
	} else {
		return 1.0F;
	}
}
