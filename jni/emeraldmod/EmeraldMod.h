#pragma once

#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/item/BlockItem.h"
#include "minecraftpe/world/item/Item.h"

class EmeraldMod {
public:
	static void initItems();
	static void initBlocks();
	static void initBlockItems();
	static void initCreativeItems();
	static void initCreativeBlocks();

	static Block* mBrick;
	static Block* mPlanks;
	static Block* mSlab;
	
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
};

