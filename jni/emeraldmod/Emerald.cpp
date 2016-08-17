#include "Emerald.h"

#include "items/EmeraldArmor.h"
#include "items/SwordItem.h"
#include "items/SuperSwordItem.h"
#include "items/PickaxeItem.h"
#include "items/AxeItem.h"
#include "items/PaxItem.h"
#include "items/ShovelItem.h"
#include "items/HoeItem.h"
#include "items/FlintAndEmerald.h"
#include "items/EmeraldBowItem.h"
#include "items/StickItem.h"

#include "blocks/EmeraldSlabBlock.h"
#include "blocks/EmeraldBrickBlock.h"
#include "blocks/EmeraldPlanksBlock.h"

Block* Emerald::mSlab;
Block* Emerald::mBrick;
Block* Emerald::mPlanks;

Item* Emerald::mHelmet;
Item* Emerald::mChestplate;
Item* Emerald::mLeggings;
Item* Emerald::mBoots;
Item* Emerald::mSword;
Item* Emerald::mSuperSword;
Item* Emerald::mPickaxe;
Item* Emerald::mAxe;
Item* Emerald::mShovel;
Item* Emerald::mHoe;
Item* Emerald::mPax;
Item* Emerald::mFlintAndEmerald;
Item* Emerald::mBow;
Item* Emerald::mStick;

void Emerald::initBlocks()
{
	Block::mBlocks[230] = mSlab = (new EmeraldSlabBlock(230))->init();
	Block::mBlocks[231] = mBrick = (new EmeraldBrickBlock(231))->init();
	Block::mBlocks[232] = mPlanks = (new EmeraldPlanksBlock(232))->init();
}

void Emerald::initBlockGr()
{
	
}

void Emerald::initBlockItems()
{
	Item::mItems[mSlab->id] = new BlockItem(mSlab->getDescriptionId(), mSlab->id - 256);
	Item::mItems[mBrick->id] = new BlockItem(mBrick->getDescriptionId(), mBrick->id - 256);
	Item::mItems[mPlanks->id] = new BlockItem(mPlanks->getDescriptionId(), mPlanks->id - 256);
}

void Emerald::initItems()
{
	Item::mItems[2000] = mHelmet = new EmeraldHelmet(2000 - 256);
	Item::mItems[2001] = mChestplate = new EmeraldChestplate(2001 - 256);
	Item::mItems[2002] = mLeggings = new EmeraldLeggings(2002 - 256);
	Item::mItems[2003] = mBoots = new EmeraldBoots(2003 - 256);
	Item::mItems[2004] = mSword = new SwordItem(2004 - 256);
	Item::mItems[2005] = mSuperSword = new SuperSwordItem(2005 - 256);
	Item::mItems[2006] = mPickaxe = new PickaxeItem(2006 - 256);
	Item::mItems[2007] = mAxe = new AxeItem(2007 - 256);
	Item::mItems[2008] = mPax = new PaxItem(2008 - 256);
	Item::mItems[2009] = mShovel = new ShovelItem(2009 - 256);
	Item::mItems[2010] = mHoe = new HoeItem(2010 - 256);
	Item::mItems[2011] = mFlintAndEmerald = new FlintAndEmerald(2011 - 256);
	Item::mItems[2012] = mBow = new EmeraldBowItem(2012 - 256);
	Item::mItems[2013] = mStick = new StickItem(2013 - 256);
} 

void Emerald::initCreativeItems()
{
	Item::addCreativeItem(mHelmet, 0);
	Item::addCreativeItem(mChestplate, 0);
	Item::addCreativeItem(mLeggings, 0);
	Item::addCreativeItem(mBoots, 0);
	Item::addCreativeItem(mSword, 0);
	Item::addCreativeItem(mSuperSword, 0);
	Item::addCreativeItem(mPickaxe, 0);
	Item::addCreativeItem(mAxe, 0);
	Item::addCreativeItem(mPax, 0);
	Item::addCreativeItem(mShovel, 0);
	Item::addCreativeItem(mHoe, 0);
	Item::addCreativeItem(mFlintAndEmerald, 0);
	Item::addCreativeItem(mBow, 0);
	Item::addCreativeItem(mStick, 0);
}

void Emerald::initCreativeBlocks()
{
	Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mPlanks, 0);
}

