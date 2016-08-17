#include "PaxItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"
#include "../Emerald.h"

PaxItem::PaxItem(short itemId) : Item("emeraldPax", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_pax", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

void PaxItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

void PaxItem::mineBlock(ItemInstance *item, BlockID blockid, int x, int y, int z, Mob *mob)
{
	Item::mItems[277]->mineBlock(item, blockId, x, y, z, mob);
	Item::mItems[278]->mineBlock(item, blockId, x, y, z, mob);
}

bool PaxItem::canDestroySpecial(const Block *block) const
{
	return (Item::mItems[277]->canDestroySpecial(block) || Item::mItems[278]->canDestroySpecial(block));
}

float PaxItem::getDestroySpeed(ItemInstance *item, Block *block)
{
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
	|| block == Emerald::mPlanks)
		return 50.0F;
	else
		return 1.0F;
}

