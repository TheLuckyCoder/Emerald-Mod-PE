#include "Emerald.h"

#include "minecraftpe/world/level/block/ThinFenceBlock.h"
#include "minecraftpe/world/level/block/SlabBlock.h"
#include "blocks/EmeraldMushroomBlock.h"
#include "blocks/EmeraldWoodBlock.h"

#include "items/EmeraldArmor.h"
#include "items/SwordItem.h"
#include "items/SuperSwordItem.h"
#include "items/PickaxeItem.h"
#include "items/SuperPickaxeItem.h"
#include "items/AxeItem.h"
#include "items/SuperAxeItem.h"
#include "items/PaxItem.h"
#include "items/ShovelItem.h"
#include "items/SuperShovelItem.h"
#include "items/HoeItem.h"
#include "items/SuperHoeItem.h"
#include "items/SpearItem.h"
#include "items/BattleAxeItem.h"
#include "items/FlintAndEmerald.h"
#include "items/AppleItem.h"
#include "items/FertilizerItem.h"

Item* Emerald::mHelmet;
Item* Emerald::mChestplate;
Item* Emerald::mLeggings;
Item* Emerald::mBoots;
Item* Emerald::mSword;
Item* Emerald::mSuperSword;
Item* Emerald::mPickaxe;
Item* Emerald::mSuperPickaxe;
Item* Emerald::mAxe;
Item* Emerald::mSuperAxe;
Item* Emerald::mShovel;
Item* Emerald::mSuperShovel;
Item* Emerald::mHoe;
Item* Emerald::mSuperHoe;
Item* Emerald::mPax;
Item* Emerald::mFlintAndEmerald;
Item* Emerald::mSpear;
Item* Emerald::mBattleAxe;
Item* Emerald::mStick;
Item* Emerald::mNugget;
Item* Emerald::mApple;
Item* Emerald::mFertilizer;

Block* Emerald::mPlanks;
Block* Emerald::mBrick;
Block* Emerald::mFence;
Block* Emerald::mSlab;
Block* Emerald::mMushroom;
Block* Emerald::mWood;

void Emerald::registerItems()
{
	mHelmet = &registerItem<EmeraldHelmet>("emerald_helmet", 3900 - 256);
	mChestplate = &registerItem<EmeraldChestplate>("emerald_chestplate", 3901 - 256);
	mLeggings = &registerItem<EmeraldLeggings>("emerald_leggings", 3902 - 256);
	mBoots = &registerItem<EmeraldBoots>("emerald_boots", 3903 - 256);
	mSword = &registerItem<SwordItem>("emerald_sword", 3904 - 256);
	mSuperSword = &registerItem<SuperSwordItem>("emerald_sword_super", 3905 - 256);
	mPickaxe = &registerItem<PickaxeItem>("emerald_pickaxe", 3906 - 256);
	mSuperPickaxe = &registerItem<SuperPickaxeItem>("emerald_pickaxe_super", 3907 - 256);
	mAxe = &registerItem<AxeItem>("emerald_axe", 3908 - 256);
	mSuperAxe = &registerItem<SuperAxeItem>("emerald_axe_super", 3909 - 256);
	mShovel = &registerItem<ShovelItem>("emerald_shovel", 3910 - 256);
	mSuperShovel = &registerItem<SuperShovelItem>("emerald_shovel_super", 3911 - 256);
	mHoe = &registerItem<HoeItem>("emerald_hoe", 3912 - 256);
	mSuperHoe = &registerItem<SuperHoeItem>("emerald_hoe_super", 3913 - 256);
	mPax = &registerItem<PaxItem>("emerald_pax", 3914 - 256);
	mFlintAndEmerald = &registerItem<FlintAndEmerald>("flint_and_emerald", 3915 - 256);
	mSpear = &registerItem<SpearItem>("emerald_spear", 3916 - 256);
	mBattleAxe = &registerItem<BattleAxeItem>("emerald_battle_axe", 3917 - 256);
	mStick = &registerItem<Item>("emerald_stick", 3918 - 256);
	mNugget = &registerItem<Item>("emerald_nugget", 3919 - 256);
	mApple = &registerItem<AppleItem>("emerald_apple", 3920 - 256);
	//mFertilizer = &registerItem<FertilizerItem>("emerald_fertilizer", 3921 - 256);
}

void Emerald::setItemTextures()
{
	mHelmet->setIcon("emerald_helmet", 0);
	mChestplate->setIcon("emerald_chestplate", 0);
	mLeggings->setIcon("emerald_leggings", 0);
	mBoots->setIcon("emerald_boots", 0);
	mSword->setIcon("emerald_sword", 0);
	mSuperSword->setIcon("emerald_sword", 1);
	mPickaxe->setIcon("emerald_pickaxe", 0);
	mSuperPickaxe->setIcon("emerald_pickaxe", 1);
	mAxe->setIcon("emerald_axe", 0);
	mSuperAxe->setIcon("emerald_axe", 1);
	mPax->setIcon("emerald_pax", 0);
	mShovel->setIcon("emerald_shovel", 0);
	mSuperShovel->setIcon("emerald_shovel", 1);
	mHoe->setIcon("emerald_hoe", 0);
	mSuperHoe->setIcon("emerald_hoe", 1);
	mFlintAndEmerald->setIcon("flint_and_emerald", 0);
	mSpear->setIcon("emerald_spear", 0);
	mBattleAxe->setIcon("emerald_battle_axe", 0);
	mStick->setIcon("emerald_stick", 0);
	mNugget->setIcon("emerald_nugget", 0);
	mApple->setIcon("emerald_apple", 0);
	//mFertilizer->setIcon("emerald_nugget", 0);
}

void Emerald::registerBlocks()
{
	mPlanks = &registerBlock<Block>("emerald_planks", 210, Material::getMaterial(MaterialType::WOOD));
	mPlanks->setCategory(CreativeItemCategory::BLOCKS);
	mPlanks->setDestroyTime(1.4f);
	mPlanks->setExplodeable(6);
	
	mBrick = &registerBlock<Block>("emerald_brick", 211, Material::getMaterial(MaterialType::STONE));
	mBrick->setCategory(CreativeItemCategory::BLOCKS);
	mBrick->setDestroyTime(2.0f);
	mBrick->setExplodeable(10);
	
	mFence = &registerBlock<ThinFenceBlock>("emerald_fence", 212, Material::getMaterial(MaterialType::METAL), false);
	mFence->setSolid(false);
	mFence->setCategory(CreativeItemCategory::DECORATIONS);
	mFence->setDestroyTime(2.2f);
	mFence->setExplodeable(11);
	
	mSlab = &registerBlock<SlabBlock>("emerald_slab", 213, false, Material::getMaterial(MaterialType::METAL));
	mSlab->setCategory(CreativeItemCategory::BLOCKS);
	mSlab->setDestroyTime(2.2f);
	mSlab->setExplodeable(11);
	
	mMushroom = &registerBlock<EmeraldMushroomBlock>("emerald_mushroom", 214);
	
	//mWood = &registerBlock<EmeraldWoodBlock>("emerald_wood", 215);
}

void Emerald::registerBlockItems()
{
	registerItem<BlockItem>(mPlanks->getDescriptionId(), mPlanks->blockId - 256);
	registerItem<BlockItem>(mBrick->getDescriptionId(), mBrick->blockId - 256);
	registerItem<BlockItem>(mFence->getDescriptionId(), mFence->blockId - 256);
	//registerItem<BlockItem>(mSlab->getDescriptionId(), mSlab->blockId - 256);
	registerItem<BlockItem>(mMushroom->getDescriptionId(), mMushroom->blockId - 256);
	//registerItem<BlockItem>(mWood->getDescriptionId(), mWood->blockId - 256);
}

void Emerald::initBlockGraphics()
{
	BlockGraphics::mBlocks[mPlanks->blockId] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[mPlanks->blockId]->setTextureItem("emerald_planks");
	BlockGraphics::mBlocks[mPlanks->blockId]->setSoundType(BlockSoundType::WOOD);
	
	BlockGraphics::mBlocks[mBrick->blockId] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[mBrick->blockId]->setTextureItem("emerald_brick");
	
	BlockGraphics::mBlocks[mFence->blockId] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[mFence->blockId]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[mFence->blockId]->setBlockShape(BlockShape::FENCE);
	
	/*BlockGraphics::mBlocks[mSlab->blockId] = new BlockGraphics("emerald_block");
	BlockGraphics::mBlocks[mSlab->blockId]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[mSlab->blockId]->setSoundType(BlockSoundType::METAL);*/
	
	BlockGraphics::mBlocks[mMushroom->blockId] = new BlockGraphics("sapling");
	BlockGraphics::mBlocks[mMushroom->blockId]->setTextureItem("emerald_mushroom");
	BlockGraphics::mBlocks[mMushroom->blockId]->setBlockShape(BlockShape::CROSS_TEXTURE);
	BlockGraphics::mBlocks[mMushroom->blockId]->setSoundType(BlockSoundType::GRASS);
	
	//BlockGraphics::mBlocks[mWood->blockId] = new BlockGraphics("dirt");
	//BlockGraphics::mBlocks[mWood->blockId]->setTextureItem("log_top", "log_top", "log_side");
	//BlockGraphics::mBlocks[mWood->blockId]->setSoundType(BlockSoundType::WOOD);
}

void Emerald::initCreativeItems()
{
	Item::addCreativeItem(mSword, 0);
	Item::addCreativeItem(mSuperSword, 0);
	Item::addCreativeItem(mPickaxe, 0);
	Item::addCreativeItem(mSuperPickaxe, 0);
	Item::addCreativeItem(mAxe, 0);
	Item::addCreativeItem(mSuperAxe, 0);
	Item::addCreativeItem(mPax, 0);
	Item::addCreativeItem(mShovel, 0);
	Item::addCreativeItem(mSuperShovel, 0);
	Item::addCreativeItem(mHoe, 0);
	Item::addCreativeItem(mSuperHoe, 0);
	Item::addCreativeItem(mFlintAndEmerald, 0);
	Item::addCreativeItem(mSpear, 0);
	Item::addCreativeItem(mBattleAxe, 0);
	Item::addCreativeItem(mStick, 0);
	Item::addCreativeItem(mNugget, 0);
	Item::addCreativeItem(mApple, 0);
}

void Emerald::initCreativeBlocks()
{
	Item::addCreativeItem(mPlanks, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mFence, 0);
	//Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mMushroom, 0);
	//Item::addCreativeItem(mWood, 0);
}

