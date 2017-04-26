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
#include "items/AxeItem.h"
#include "items/PaxItem.h"
#include "items/ShovelItem.h"
#include "items/HoeItem.h"
#include "items/FlintAndEmerald.h"
#include "items/EmeraldBowItem.h"

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
Item* Emerald::mNugget;

Block* Emerald::mPlanks;
Block* Emerald::mBrick;
Block* Emerald::mFence;
Block* Emerald::mSlab;
Block* Emerald::mLadder;
Block* Emerald::mMushroom;

void Emerald::initItems()
{
	//mHelmet = new EmeraldHelmet(3800);
	//mChestplate = new EmeraldChestplate(3801);
	//mLeggings = new EmeraldLeggings(3802);
	//mBoots = new EmeraldBoots(3803);
	mSword = new SwordItem(3804);
	mSuperSword = new SuperSwordItem(3805);
	mPickaxe = new PickaxeItem(3806);
	mAxe = new AxeItem(3807);
	mPax = new PaxItem(3808);
	mShovel = new ShovelItem(3809);
	mHoe = new HoeItem(3810);
	mFlintAndEmerald = new FlintAndEmerald(3811);
	//mBow = new EmeraldBowItem(3812);
	Item::mItems[3813] = mStick = (new Item("emeraldStick", 3813 - 256))->setIcon("emerald_stick", 0);
	Item::mItems[3814] = mNugget = (new Item("emeraldNugget", 3814 - 256))->setIcon("emerald_nugget", 0);
}

void Emerald::initBlocks()
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
	mFence->setDestroyTime(2.0f);
	mFence->setExplodeable(8.0f);
	
	Block::mBlocks[235] = mSlab = new SlabBlock("emeraldSlab", 235, false, Material::getMaterial(MaterialType::METAL));
	mSlab->setCategory(CreativeItemCategory::Blocks);
	mSlab->setDestroyTime(2.2f);
	mSlab->setExplodeable(8.0f);
	
	mMushroom = new EmeraldMushroomBlock(236);
	
	//Block::mBlocks[237] = mLadder = new LadderBlock("emeraldLadder", 237);
	//mLadder->setCategory(CreativeItemCategory::Decorations);
}

void Emerald::initBlockItems()
{
	Item::mItems[mPlanks->blockId] = new BlockItem(mPlanks->getDescriptionId(), mPlanks->blockId - 256);
	Item::mItems[mBrick->blockId] = new BlockItem(mBrick->getDescriptionId(), mBrick->blockId - 256);
	Item::mItems[mFence->blockId] = new BlockItem(mFence->getDescriptionId(), mFence->blockId - 256);
	Item::mItems[mSlab->blockId] = new BlockItem(mSlab->getDescriptionId(), mSlab->blockId - 256);
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
	
	BlockGraphics::mBlocks[mSlab->blockId] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[mSlab->blockId]->setTextureItem("emerald_block");
	BlockGraphics::mBlocks[mSlab->blockId]->setSoundType(BlockSoundType::METAL);
	
	BlockGraphics::mBlocks[mMushroom->blockId] = new BlockGraphics("sapling");
	BlockGraphics::mBlocks[mMushroom->blockId]->setTextureItem("emerald_mushroom");
	BlockGraphics::mBlocks[mMushroom->blockId]->setBlockShape(BlockShape::CROSS_TEXTURE);
	BlockGraphics::mBlocks[mMushroom->blockId]->setSoundType(BlockSoundType::GRASS);
	
	//BlockGraphics::mBlocks[mLadder->blockId] = new BlockGraphics("ladder");
	//BlockGraphics::mBlocks[mLadder->blockId]->setTextureItem("emerald_ladder");
	//BlockGraphics::mBlocks[mLadder->blockId]->setSoundType(BlockSoundType::LADDER);
	//BlockGraphics::mBlocks[mLadder->blockId]->setBlockShape(BlockShape::LADDER);
}

void Emerald::initCreativeItems()
{
	//Item::addCreativeItem(3800, 0);
	//Item::addCreativeItem(3801, 0);
	//Item::addCreativeItem(3802, 0);
	//Item::addCreativeItem(3803, 0);
	Item::addCreativeItem(3804, 0);
	Item::addCreativeItem(3805, 0);
	Item::addCreativeItem(3806, 0);
	Item::addCreativeItem(3807, 0);
	Item::addCreativeItem(3808, 0);
	Item::addCreativeItem(3809, 0);
	Item::addCreativeItem(3810, 0);
	Item::addCreativeItem(3811, 0);
	//Item::addCreativeItem(3812, 0);
	Item::addCreativeItem(3813, 0);
	Item::addCreativeItem(3814, 0);
}

void Emerald::initCreativeBlocks()
{
	Item::addCreativeItem(mPlanks, 0);
	Item::addCreativeItem(mBrick, 0);
	Item::addCreativeItem(mFence, 0);
	Item::addCreativeItem(mSlab, 0);
	Item::addCreativeItem(mMushroom, 0);
}

