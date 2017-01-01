#include "EmeraldMod.h"

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

void EmeraldMod::initItems()
{
	//Item::mItems[2300] = mHelmet = new EmeraldHelmet(2300 - 256);
	//Item::mItems[2301] = mChestplate = new EmeraldChestplate(2301 - 256);
	//Item::mItems[2302] = mLeggings = new EmeraldLeggings(2302 - 256);
	//Item::mItems[2303] = mBoots = new EmeraldBoots(2303 - 256);
	Item::mItems[2304] = mSword = new SwordItem(2304 - 256);
	Item::mItems[2305] = mSuperSword = new SuperSwordItem(2305 - 256);
	Item::mItems[2306] = mPickaxe = new PickaxeItem(2306 - 256);
	Item::mItems[2307] = mAxe = new AxeItem(2307 - 256);
	Item::mItems[2308] = mPax = new PaxItem(2308 - 256);
	Item::mItems[2309] = mShovel = new ShovelItem(2309 - 256);
	Item::mItems[2310] = mHoe = new HoeItem(2310 - 256);
	Item::mItems[2311] = mFlintAndEmerald = new FlintAndEmerald(2311 - 256);
	Item::mItems[2312] = mBow = new EmeraldBowItem(2312 - 256);
	Item::mItems[2313] = mStick = (new Item("emeraldStick", 2313 - 256))->setIcon("emerald_stick", 0);
}

void EmeraldMod::initCreativeItems()
{
	//DO NOT use pointers here, else the game will crash
	
	/*Item::addCreativeItem(2000, 0);
	Item::addCreativeItem(2001, 0);
	Item::addCreativeItem(2002, 0);
	Item::addCreativeItem(2003, 0);*/
	Item::addCreativeItem(2004, 0);
	Item::addCreativeItem(2005, 0);
	Item::addCreativeItem(2006, 0);
	Item::addCreativeItem(2007, 0);
	Item::addCreativeItem(2008, 0);
	Item::addCreativeItem(2009, 0);
	Item::addCreativeItem(2010, 0);
	//Item::addCreativeItem(2011, 0);
	Item::addCreativeItem(2013, 0);
}

