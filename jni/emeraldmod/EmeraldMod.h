#pragma once

#include "minecraftpe/world/item/BlockItem.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/client/renderer/block/BlockGraphics.h"

class EmeraldMod
{
public:
	static void initItems();
	static void initCreativeItems();
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	
	static Item* mHelmet;
	static Item* mChestplate;
	static Item* mLeggings;
	static Item* mBoots;
	static Item* mSword;
	static Item* mSuperSword;
	static Item* mPickaxe;
	static Item* mAxe;
	static Item* mPax;
	static Item* mShovel;
	static Item* mHoe;
	static Item* mFlintAndEmerald;
	static Item* mBow;
	static Item* mStick;
	static Item* mDust;
	
	static Block* mWood;
	static Block* mPlanks;
	static Block* mBrick;
	static Block* mFence;
	static Block* mSlab;
	static Block* mTorch;
	static Block* mLadder;
};

