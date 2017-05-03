#pragma once

#include "minecraftpe/world/item/BlockItem.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/level/block/BlockGraphics.h"

class Emerald
{
public:
	static void registerItems();
	static void initClientData();
	static void registerBlocks();
	static void registerBlockItems();
	static void initBlockGraphics();
	static void initCreativeItems();
	static void initCreativeBlocks();
	
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
	static Item* mBattleAxe;
	static Item* mStick;
	static Item* mNugget;
	
	static Block* mPlanks;
	static Block* mBrick;
	static Block* mFence;
	static Block* mSlab;
	static Block* mMushroom;
	static Block* mLadder;
};

