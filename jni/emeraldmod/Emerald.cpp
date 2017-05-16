#include "Emerald.h"

#include "minecraftpe/world/level/block/FenceBlock.h"
#include "minecraftpe/world/level/block/SlabBlock.h"
#include "minecraftpe/world/level/block/TorchBlock.h"
#include "minecraftpe/world/level/block/LadderBlock.h"
#include "blocks/EmeraldMushroomBlock.h"

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

Block* Emerald::mPlanks;
Block* Emerald::mBrick;
Block* Emerald::mFence;
Block* Emerald::mSlab;
Block* Emerald::mLadder;
Block* Emerald::mMushroom;

void Emerald::registerItems()
{
	mSword = new SwordItem(3904);
	mSuperSword = new SuperSwordItem(3905);
	mPickaxe = new PickaxeItem(3906);
	mSuperPickaxe = new SuperPickaxeItem(3907);
	mAxe = new AxeItem(3908);
	mSuperAxe = new SuperAxeItem(3909);
	mShovel = new ShovelItem(3910);
	mSuperShovel = new SuperShovelItem(3911);
	mHoe = new HoeItem(3912);
	mSuperHoe = new SuperHoeItem(3913);
	mPax = new PaxItem(3914);
	mFlintAndEmerald = new FlintAndEmerald(3915);
	mSpear = new SpearItem(3916);
	mBattleAxe = new BattleAxeItem(3917);
	Item::mItems[3918] = mStick = new Item("emeraldStick", 3918 - 256);
	Item::mItems[3919] = mNugget = new Item("emeraldNugget", 3919 - 256);
}

void Emerald::initClientData()
{
	//mHelmet = new EmeraldHelmet(3900);
	//mChestplate = new EmeraldChestplate(3901);
	//mLeggings = new EmeraldLeggings(3902);
	//mBoots = new EmeraldBoots(3903);
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
}

void Emerald::registerBlocks()
{
	Block::mBlocks[232] = mPlanks = new Block("emeraldPlanks", 232, Material::getMaterial(MaterialType::WOOD));
	mPlanks->setCategory(CreativeItemCategory::Blocks);
	mPlanks->setDestroyTime(1.4f);
	mPlanks->setExplodeable(5.0f);
	
	Block::mBlocks[233] = mBrick = new Block("emeraldBrick", 233, Material::getMaterial(MaterialType::STONE));
	mBrick->setCategory(CreativeItemCategory::Blocks);
	mBrick->setDestroyTime(2.0f);
	mBrick->setExplodeable(8.0f);
	
	Block::mBlocks[234] = mFence = new FenceBlock("emeraldFence", 234, Material::getMaterial(MaterialType::METAL));
	mFence->setSolid(false);
	mFence->setCategory(CreativeItemCategory::Decorations);
	mFence->setDestroyTime(2.2f);
	mFence->setExplodeable(8.0f);
	
	/*Block::mBlocks[235] = mSlab = new SlabBlock("emeraldSlab", 235, false, Material::getMaterial(MaterialType::METAL));
	mSlab->setCategory(CreativeItemCategory::Blocks);
	mSlab->setDestroyTime(2.2f);
	mSlab->setExplodeable(8.0f);*/
	
	mMushroom = new EmeraldMushroomBlock(236);
	
	//Block::mBlocks[237] = mLadder = new LadderBlock("emeraldLadder", 237);
	//mLadder->setCategory(CreativeItemCategory::Decorations);
}

void Emerald::registerBlockItems()
{
	Item::mItems[mPlanks->blockId] = new BlockItem(mPlanks->getDescriptionId(), mPlanks->blockId - 256);
	Item::mItems[mBrick->blockId] = new BlockItem(mBrick->getDescriptionId(), mBrick->blockId - 256);
	Item::mItems[mFence->blockId] = new BlockItem(mFence->getDescriptionId(), mFence->blockId - 256);
	//Item::mItems[mSlab->blockId] = new BlockItem(mSlab->getDescriptionId(), mSlab->blockId - 256);
	Item::mItems[mMushroom->blockId] = new BlockItem(mMushroom->getDescriptionId(), mMushroom->blockId - 256);
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
	
	/*BlockGraphics::mBlocks[mSlab->blockId] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[mSlab->blockId]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[mSlab->blockId]->setSoundType(BlockSoundType::METAL);*/
	
	BlockGraphics::mBlocks[mMushroom->blockId] = new BlockGraphics("sapling");
	BlockGraphics::mBlocks[mMushroom->blockId]->setTextureItem("emerald_mushroom");
	BlockGraphics::mBlocks[mMushroom->blockId]->setBlockShape(BlockShape::CROSS_TEXTURE);
	BlockGraphics::mBlocks[mMushroom->blockId]->setSoundType(BlockSoundType::GRASS);
	
	/*BlockGraphics::mBlocks[mLadder->blockId] = new BlockGraphics("ladder");
	BlockGraphics::mBlocks[mLadder->blockId]->setTextureItem("emerald_ladder");
	BlockGraphics::mBlocks[mLadder->blockId]->setSoundType(BlockSoundType::LADDER);
	BlockGraphics::mBlocks[mLadder->blockId]->setBlockShape(BlockShape::LADDER);*/
}

void Emerald::initCreativeItems()
{
	for (short id = 3904; id <= 3919; ++id)
		Item::addCreativeItem(id, 0);
	/*Item::addCreativeItem(mSword, 0);
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
	Item::addCreativeItem(mNugget, 0);*/
}

void Emerald::initCreativeBlocks()
{
	Item::addCreativeItem(mPlanks, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mFence, 0);
	//Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mMushroom, 0);
}

