#include "Emerald.h"

#include "items/EmeraldArmorItem.h"
#include "items/SwordItem.h"
#include "items/SuperSwordItem.h"
#include "items/PickaxeItem.h"
#include "items/PaxItem.h"
#include "items/AxeItem.h"
#include "items/ShovelItem.h"
#include "items/HoeItem.h"
#include "items/FlintAndEmeraldItem.h"
#include "items/BowItem.h"
#include "items/RodItem.h"
#include "items/DustItem.h"

#include "blocks/EmeraldSlabBlock.h"
#include "blocks/EmeraldBrickBlock.h"
#include "blocks/EmeraldPlanksBlock.h"

Block* Emerald::mBrick;
Block* Emerald::mPlanks;
Block* Emerald::mSlab;

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
Item* Emerald::mRod;
Item* Emerald::mDust;

void Emerald::initBlocks()
{
	Block::mBlocks[230] = mSlab = (new EmeraldSlabBlock(233))->init();
	Block::mBlocks[231] = mBrick = (new EmeraldBrickBlock(231))->init();
	Block::mBlocks[232] = mPlanks = (new EmeraldPlanksBlock(232))->init();
}

void Emerald::initBlockItems()
{
	Item::mItems[mSlab->blockId] = new BlockItem(mSlab->getDescriptionId(), mSlab->blockId - 0x100);
	Item::mItems[mBrick->blockId] = new BlockItem(mBrick->getDescriptionId(), mBrick->blockId - 0x100);
	Item::mItems[mPlanks->blockId] = new BlockItem(mPlanks->getDescriptionId(), mPlanks->blockId - 0x100);
}

void Emerald::initItems()
{
	Item::mItems[2000] = mHelmet = new HelmetItem(2000 - 0x100);
	Item::mItems[2001] = mChestplate = new ChestplateItem(2001 - 0x100);
	Item::mItems[2002] = mLeggings = new LeggingsItem(2002 - 0x100);
	Item::mItems[2003] = mBoots = new BootsItem(2003 - 0x100);
	Item::mItems[2004] = mSword = new SwordItem(2004 - 0x100);
	Item::mItems[2005] = mSuperSword = new SuperSwordItem(2005 - 0x100);
	Item::mItems[2006] = mPickaxe = new PickaxeItem(2006 - 0x100);
	Item::mItems[2007] = mAxe = new AxeItem(2007 - 0x100);
	Item::mItems[2008] = mPax = new PaxItem(2008 - 0x100);
	Item::mItems[2009] = mShovel = new ShovelItem(2009 - 0x100);
	Item::mItems[2010] = mHoe = new HoeItem(2010 - 0x100);
	Item::mItems[2011] = mFlintAndEmerald = new FlintAndEmeraldItem(2011 - 0x100);
	Item::mItems[2012] = mBow = new BowItem(2012 - 0x100);
	Item::mItems[2013] = mRod = new RodItem(2013 - 0x100);
	Item::mItems[2014] = mDust = new DustItem(2014 - 0x100);
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
	Item::addCreativeItem(mRod, 0);
	Item::addCreativeItem(mDust, 0);
	Item::addCreativeItem(mBow, 0);
	Item::addCreativeItem(511, 0);//Beef
	Item::addCreativeItem(512, 0);//Apple
}

void Emerald::initCreativeBlocks()
{
	Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mPlanks, 0);
}
