#include "PickaxeItem.h"
#include "mcpe/world/item/ItemInstance.h"

PickaxeItem::PickaxeItem(short itemId) : Item("emeraldPickaxe", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_pickaxe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int PickaxeItem::getAttackDamage() {
	return 5.0F;
}

int PickaxeItem::getEnchantSlot() const{
	return 1024;
}

int PickaxeItem::getEnchantValue() const{
	return 1;
}

void PickaxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void PickaxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Mob *mob) {
	if(blockId == Block::mStone->blockId
	|| blockId == Block::mCobblestone->blockId
	|| blockId == Block::mGoldOre->blockId
	|| blockId == Block::mIronOre->blockId
	|| blockId == Block::mCoalOre->blockId
	|| blockId == Block::mLapisOre->blockId
	|| blockId == Block::mLapisBlock->blockId
	|| blockId == Block::mSandStone->blockId
	|| blockId == Block::mGoldenRail->blockId
	|| blockId == Block::mDetectorRail->blockId
	|| blockId == Block::mGoldBlock->blockId
	|| blockId == Block::mIronBlock->blockId
	|| blockId == Block::mStoneSlab->blockId
	|| blockId == Block::mBrick->blockId
	|| blockId == Block::mMossyCobblestone->blockId
	|| blockId == Block::mObsidian->blockId
	|| blockId == Block::mMobSpawner->blockId
	|| blockId == Block::mDiamondOre->blockId
	|| blockId == Block::mDiamondBlock->blockId
	|| blockId == Block::mFurnace->blockId
	|| blockId == Block::mLitFurnace->blockId
	|| blockId == Block::mRail->blockId
	|| blockId == Block::mStoneStairs->blockId
	|| blockId == Block::mStonePressurePlate->blockId
	|| blockId == Block::mIronDoor->blockId
	|| blockId == Block::mRedStoneOre->blockId
	|| blockId == Block::mLitRedStoneOre->blockId
	|| blockId == Block::mStoneButton->blockId
	|| blockId == Block::mIce->blockId
	|| blockId == Block::mClay->blockId
	|| blockId == Block::mNetherrack->blockId
	|| blockId == Block::mGlowStone->blockId
	|| blockId == Block::mStoneBrick->blockId
	|| blockId == Block::mIronFence->blockId
	|| blockId == Block::mBrickStairs->blockId
	|| blockId == Block::mStoneBrickStairs->blockId
	|| blockId == Block::mNetherBrick->blockId
	|| blockId == Block::mNetherFence->blockId
	|| blockId == Block::mNetherBrickStairs->blockId
	|| blockId == Block::mBrewingStand->blockId
	|| blockId == Block::mEndStone->blockId
	|| blockId == Block::mUnlitRedStoneLamp->blockId
	|| blockId == Block::mLitRedStoneLamp->blockId
	|| blockId == Block::mActivatorRail->blockId
	|| blockId == Block::mEmeraldOre->blockId
	|| blockId == Block::mEmeraldBlock->blockId
	|| blockId == Block::mAnvil->blockId
	|| blockId == Block::mLightWeightedPressurePlate->blockId
	|| blockId == Block::mHeavyWeightedPressurePlate->blockId
	|| blockId == Block::mDaylightDetector->blockId
	|| blockId == Block::mRedstoneBlock->blockId
	|| blockId == Block::mQuartzOre->blockId
	|| blockId == Block::mQuartzBlock->blockId
	|| blockId == Block::mQuartzStairs->blockId
	|| blockId == Block::mStainedClay->blockId
	|| blockId == Block::mHardenedClay->blockId
	|| blockId == Block::mCoalBlock->blockId
	|| blockId == Block::mPackedIce->blockId
	|| blockId == Emerald::mSlab->blockId
	|| blockId == Emerald::mBrick->blockId){
		item->hurtAndBreak(1, mob);
	} else{
		item->hurtAndBreak(2, mob);
	}
}

bool PickaxeItem::canDestroySpecial(const Block* block) const {
	return Item::mItems[278]->canDestroySpecial(block);
}

float PickaxeItem::getDestroySpeed(ItemInstance *item, Block *block) {
	if(block == Block::mStone 
	|| block == Block::mCobblestone
	|| block == Block::mGoldOre 
	|| block == Block::mIronOre 
	|| block == Block::mCoalOre
	|| block == Block::mLapisOre
	|| block == Block::mLapisBlock
	|| block == Block::mSandStone
	|| block == Block::mGoldenRail
	|| block == Block::mDetectorRail
	|| block == Block::mGoldBlock
	|| block == Block::mIronBlock
	|| block == Block::mStoneSlab
	|| block == Block::mBrick
	|| block == Block::mMossyCobblestone
	|| block == Block::mObsidian 
	|| block == Block::mMobSpawner
	|| block == Block::mDiamondOre
	|| block == Block::mDiamondBlock
	|| block == Block::mFurnace
	|| block == Block::mLitFurnace
	|| block == Block::mRail
	|| block == Block::mStoneStairs
	|| block == Block::mStonePressurePlate
	|| block == Block::mIronDoor
	|| block == Block::mRedStoneOre
	|| block == Block::mLitRedStoneOre
	|| block == Block::mStoneButton
	|| block == Block::mIce
	|| block == Block::mClay
	|| block == Block::mNetherrack
	|| block == Block::mGlowStone
	|| block == Block::mStoneBrick
	|| block == Block::mIronFence
	|| block == Block::mBrickStairs
	|| block == Block::mStoneBrickStairs
	|| block == Block::mNetherBrick
	|| block == Block::mNetherFence
	|| block == Block::mNetherBrickStairs
	|| block == Block::mBrewingStand
	|| block == Block::mEndStone
	|| block == Block::mUnlitRedStoneLamp
	|| block == Block::mLitRedStoneLamp
	|| block == Block::mActivatorRail
	|| block == Block::mEmeraldOre
	|| block == Block::mEmeraldBlock
	|| block == Block::mAnvil
	|| block == Block::mLightWeightedPressurePlate
	|| block == Block::mHeavyWeightedPressurePlate
	|| block == Block::mDaylightDetector
	|| block == Block::mRedstoneBlock
	|| block == Block::mQuartzOre
	|| block == Block::mQuartzBlock
	|| block == Block::mQuartzStairs
	|| block == Block::mStainedClay
	|| block == Block::mHardenedClay
	|| block == Block::mCoalBlock
	|| block == Block::mPackedIce
	|| block == Emerald::mSlab
	|| block == Emerald::mBrick) {
		return 50.0F;
	} else {
		return 1.0F;
	}
}
