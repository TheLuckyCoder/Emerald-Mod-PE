#pragma once

#include <map>

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/BlockItem.h"
#include "mcpe/world/item/Item.h"

class Emerald {
public:
	void initItems();
	void initBlocks();
	void initBlockItems();
	void initCreativeItems();
	void initCreativeBlocks();

public:
	static Block* mBrick;
	static Block* mPlanks;
	static Block* mSlab;
	static Block* mDoubleSlab;
	
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
	static Item* mRod;
	static Item* mDust;
};
