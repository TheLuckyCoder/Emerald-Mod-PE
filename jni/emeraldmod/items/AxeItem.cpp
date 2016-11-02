#include "AxeItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "../EmeraldMod.h"

AxeItem::AxeItem(short itemId) : Item("emeraldAxe", itemId)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("emerald_axe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

void AxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	item->hurtAndBreak(2, victim);
}

void AxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Mob *mob)
{
	Item::mItems[279]->mineBlock(item, blockId, x, y, z, mob);
}

float AxeItem::getDestroySpeed(ItemInstance *item, Block *block)
{
	if(block == Block::mWoodPlanks
	||block == Block::mLog
	||block == Block::mChest
	||block == Block::mSign
	||block == Block::mWoodenDoor
	||block == Block::mLadder
	||block == Block::mWallSign
	||block == Block::mWoodPressurePlate
	||block == Block::mFence
	||block == Block::mWoodButton
	||block == Block::mTrappedChest
	||block == Block::mWoodenSlab
	||block == Block::mAcaciaStairs
	||block == Block::mDarkOakStairs
	||block == Block::mSpuceFenceGate
	||block == Block::mBirchFenceGate
	||block == Block::mJungleFenceGate
	||block == Block::mDarkOakFenceGate
	||block == Block::mAcaciaFenceGate
	||block == Block::mWoodenDoorSpruce
	||block == Block::mWoodenDoorBirch
	||block == Block::mWoodenDoorJungle
	||block == Block::mWoodenDoorAcacia
	||block == Block::mWoodenDoorDarkOak
	||block == Block::mWorkBench)
		return 50.0F;
	else
		return 1.0F;
}

