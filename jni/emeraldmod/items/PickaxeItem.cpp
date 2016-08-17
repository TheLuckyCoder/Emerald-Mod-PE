#include "PickaxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/block/Block.h"
#include "../Emerald.h"

PickaxeItem::PickaxeItem(short itemId) : Item("emeraldPickaxe", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_pickaxe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

void PickaxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void PickaxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Mob *mob) {
	Item::mItems[278]->mineBlock(item, blockId, x, y, z, mob);
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
	|| block == Block::mObserver
	|| block == Emerald::mSlab
	|| block == Emerald::mBrick)
		return 50.0F;
}

