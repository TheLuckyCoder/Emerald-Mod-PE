#include "PaxItem.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/level/block/Block.h"
#include "../Emerald.h"

PaxItem::PaxItem(short itemId) : Item("emeraldPax", itemId)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("emerald_pax", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int PaxItem::getAttackDamage() {
	return 5.0F;
}

int PaxItem::getEnchantSlot() const{
	return 1024;
}

int PaxItem::getEnchantValue() const{
	return 1;
}

void PaxItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void PaxItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob) {
	if(blockid == Block::mWoodPlanks->blockId
	|| blockid == Block::mLog->blockId
	|| blockid == Block::mChest->blockId
	|| blockid == Block::mSign->blockId
	|| blockid == Block::mWoodenDoor->blockId
	|| blockid == Block::mLadder->blockId
	|| blockid == Block::mWallSign->blockId
	|| blockid == Block::mWoodPressurePlate->blockId
	|| blockid == Block::mFence->blockId
	|| blockid == Block::mWoodButton->blockId
	|| blockid == Block::mTrappedChest->blockId
	|| blockid == Block::mWoodenSlab->blockId
	|| blockid == Block::mAcaciaStairs->blockId
	|| blockid == Block::mDarkOakStairs->blockId
	|| blockid == Block::mSpuceFenceGate->blockId
	|| blockid == Block::mBirchFenceGate->blockId
	|| blockid == Block::mJungleFenceGate->blockId
	|| blockid == Block::mDarkOakFenceGate->blockId
	|| blockid == Block::mAcaciaFenceGate->blockId
	|| blockid == Block::mWoodenDoorSpruce->blockId
	|| blockid == Block::mWoodenDoorBirch->blockId
	|| blockid == Block::mWoodenDoorJungle->blockId
	|| blockid == Block::mWoodenDoorAcacia->blockId
	|| blockid == Block::mWoodenDoorDarkOak->blockId
	|| blockid == Block::mWorkBench->blockId
	|| blockid == Block::mStone->blockId
	|| blockid == Block::mCobblestone->blockId
	|| blockid == Block::mGoldOre->blockId
	|| blockid == Block::mIronOre->blockId
	|| blockid == Block::mCoalOre->blockId
	|| blockid == Block::mLapisOre->blockId
	|| blockid == Block::mLapisBlock->blockId
	|| blockid == Block::mSandStone->blockId
	|| blockid == Block::mGoldenRail->blockId
	|| blockid == Block::mDetectorRail->blockId
	|| blockid == Block::mGoldBlock->blockId
	|| blockid == Block::mIronBlock->blockId
	|| blockid == Block::mStoneSlab->blockId
	|| blockid == Block::mBrick->blockId
	|| blockid == Block::mMossyCobblestone->blockId
	|| blockid == Block::mObsidian->blockId
	|| blockid == Block::mMobSpawner->blockId
	|| blockid == Block::mDiamondOre->blockId
	|| blockid == Block::mDiamondBlock->blockId
	|| blockid == Block::mFurnace->blockId
	|| blockid == Block::mLitFurnace->blockId
	|| blockid == Block::mRail->blockId
	|| blockid == Block::mStoneStairs->blockId
	|| blockid == Block::mStonePressurePlate->blockId
	|| blockid == Block::mIronDoor->blockId
	|| blockid == Block::mRedStoneOre->blockId
	|| blockid == Block::mLitRedStoneOre->blockId
	|| blockid == Block::mStoneButton->blockId
	|| blockid == Block::mIce->blockId
	|| blockid == Block::mClay->blockId
	|| blockid == Block::mNetherrack->blockId
	|| blockid == Block::mGlowStone->blockId
	|| blockid == Block::mStoneBrick->blockId
	|| blockid == Block::mIronFence->blockId
	|| blockid == Block::mBrickStairs->blockId
	|| blockid == Block::mStoneBrickStairs->blockId
	|| blockid == Block::mNetherBrick->blockId
	|| blockid == Block::mNetherFence->blockId
	|| blockid == Block::mNetherBrickStairs->blockId
	|| blockid == Block::mBrewingStand->blockId
	|| blockid == Block::mEndStone->blockId
	|| blockid == Block::mUnlitRedStoneLamp->blockId
	|| blockid == Block::mLitRedStoneLamp->blockId
	|| blockid == Block::mActivatorRail->blockId
	|| blockid == Block::mEmeraldOre->blockId
	|| blockid == Block::mEmeraldBlock->blockId
	|| blockid == Block::mAnvil->blockId
	|| blockid == Block::mLightWeightedPressurePlate->blockId
	|| blockid == Block::mHeavyWeightedPressurePlate->blockId
	|| blockid == Block::mDaylightDetector->blockId
	|| blockid == Block::mRedstoneBlock->blockId
	|| blockid == Block::mQuartzOre->blockId
	|| blockid == Block::mQuartzBlock->blockId
	|| blockid == Block::mQuartzStairs->blockId
	|| blockid == Block::mStainedClay->blockId
	|| blockid == Block::mHardenedClay->blockId
	|| blockid == Block::mCoalBlock->blockId
	|| blockid == Block::mPackedIce->blockId
	|| blockid == Emerald::mSlab->blockId
	|| blockid == Emerald::mBrick->blockId
	|| blockid == Emerald::mPlanks->blockId){
		item->hurtAndBreak(1, mob);
	} else{
		item->hurtAndBreak(2, mob);
	}
}

bool PaxItem::canDestroySpecial(const Block* block) const {
	return (block == Block::mWoodPlanks
	|| block == Block::mLog
	|| block == Block::mChest
	|| block == Block::mSign
	|| block == Block::mWoodenDoor
	|| block == Block::mLadder
	|| block == Block::mWallSign
	|| block == Block::mWoodPressurePlate
	|| block == Block::mFence
	|| block == Block::mWoodButton
	|| block == Block::mTrappedChest
	|| block == Block::mWoodenSlab
	|| block == Block::mAcaciaStairs
	|| block == Block::mDarkOakStairs
	|| block == Block::mSpuceFenceGate
	|| block == Block::mBirchFenceGate
	|| block == Block::mJungleFenceGate
	|| block == Block::mDarkOakFenceGate
	|| block == Block::mAcaciaFenceGate
	|| block == Block::mWoodenDoorSpruce
	|| block == Block::mWoodenDoorBirch
	|| block == Block::mWoodenDoorJungle
	|| block == Block::mWoodenDoorAcacia
	|| block == Block::mWoodenDoorDarkOak
	|| block == Block::mWorkBench
	|| block == Block::mStone
	|| block == Block::mCobblestone
	|| block == Block::mGoldOre 
	|| block == Block::mIronOre 
	|| block == Block::mCoalOre
	|| block == Block::mLapisOre
	|| block == Block::mLapisBlock
	|| block == Block::mSandStone
	|| block == Block::mGoldBlock
	|| block == Block::mIronBlock
	|| block == Block::mStoneSlab
	|| block == Block::mBrick
	|| block == Block::mMossyCobblestone
	|| block == Block::mObsidian 
	|| block == Block::mDiamondOre
	|| block == Block::mDiamondBlock
	|| block == Block::mFurnace
	|| block == Block::mLitFurnace
	|| block == Block::mStoneStairs
	|| block == Block::mStonePressurePlate
	|| block == Block::mIronDoor
	|| block == Block::mRedStoneOre
	|| block == Block::mLitRedStoneOre
	|| block == Block::mStoneButton
	|| block == Block::mNetherrack
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
	|| block == Block::mRedstoneBlock
	|| block == Block::mQuartzOre
	|| block == Block::mQuartzBlock
	|| block == Block::mQuartzStairs
	|| block == Block::mStainedClay
	|| block == Block::mHardenedClay
	|| block == Block::mCoalBlock
	|| block == Emerald::mSlab);
}

float PaxItem::getDestroySpeed(ItemInstance *item, Block *block) {
	if(block == Block::mWoodPlanks
	|| block == Block::mLog
	|| block == Block::mChest
	|| block == Block::mSign
	|| block == Block::mWoodenDoor
	|| block == Block::mLadder
	|| block == Block::mWallSign
	|| block == Block::mWoodPressurePlate
	|| block == Block::mFence
	|| block == Block::mWoodButton
	|| block == Block::mTrappedChest
	|| block == Block::mWoodenSlab
	|| block == Block::mAcaciaStairs
	|| block == Block::mDarkOakStairs
	|| block == Block::mSpuceFenceGate
	|| block == Block::mBirchFenceGate
	|| block == Block::mJungleFenceGate
	|| block == Block::mDarkOakFenceGate
	|| block == Block::mAcaciaFenceGate
	|| block == Block::mWoodenDoorSpruce
	|| block == Block::mWoodenDoorBirch
	|| block == Block::mWoodenDoorJungle
	|| block == Block::mWoodenDoorAcacia
	|| block == Block::mWoodenDoorDarkOak
	|| block == Block::mWorkBench
	|| block == Block::mStone 
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
	|| block == Emerald::mBrick
	|| block == Emerald::mPlanks) {
		return 50.0F;
	} else {
		return 1.0F;
	}
}
