#pragma once

#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/level/block/Block.h"

class EmeraldMod {
public:
	static void initItems();
	static void initBlocks();
	static void initBlockItems();
	static void initCreativeItems();
	
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

