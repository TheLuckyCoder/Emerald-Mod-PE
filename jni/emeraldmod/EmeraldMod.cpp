#include "EmeraldMod.h"

#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/level/block/BlockHelper.h"
#include "minecraftpe/world/material/Material.h"

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

Block* EmeraldMod::mSlab;
Block* EmeraldMod::mBrick;
Block* EmeraldMod::mPlanks;

Item* EmeraldMod::mHelmet;
Item* EmeraldMod::mChestplate;
Item* EmeraldMod::mLeggings;
Item* EmeraldMod::mBoots;
Item* EmeraldMod::mSword;
Item* EmeraldMod::mSuperSword;
Item* EmeraldMod::mPickaxe;
Item* EmeraldMod::mAxe;
Item* EmeraldMod::mShovel;
Item* EmeraldMod::mHoe;
Item* EmeraldMod::mPax;
Item* EmeraldMod::mFlintAndEmerald;
Item* EmeraldMod::mBow;
Item* EmeraldMod::mStick;

void EmeraldMod::initBlocks()
{
	BlockHelper::blocks.clear();
	
	mSlab = BlockHelper::registerBlock((new Block("emeraldSlab", 230, Material::getMaterial(MaterialType::METAL)))->setCategory(CreativeItemCategory::Blocks)->init());
	mBrick = BlockHelper::registerBlock((new Block("emeraldBrick", 231, Material::getMaterial(MaterialType::STONE)))->setCategory(CreativeItemCategory::Blocks)->init());
	mPlanks = BlockHelper::registerBlock((new Block("emeraldPlanks", 232, Material::getMaterial(MaterialType::WOOD)))->setCategory(CreativeItemCategory::Blocks)->init());
}

void EmeraldMod::initBlockItems()
{
	Item::mItems[mSlab->id] = new BlockItem(mSlab->getDescriptionId(), mSlab->id - 256);
	Item::mItems[mBrick->id] = new BlockItem(mBrick->getDescriptionId(), mBrick->id - 256);
	Item::mItems[mPlanks->id] = new BlockItem(mPlanks->getDescriptionId(), mPlanks->id - 256);
}

void EmeraldMod::initItems()
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

void EmeraldMod::initCreativeItems()
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

void EmeraldMod::initCreativeBlocks()
{
	Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mPlanks, 0);
}

