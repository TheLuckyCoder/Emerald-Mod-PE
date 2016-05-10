#include "AxeItem.h"
#include "mcpe/world/item/ItemInstance.h"
#include "../Emerald.h"

AxeItem::AxeItem(short itemId) : Item("emeraldAxe", itemId)
{
	creativeCategory = CreativeItemCategory::TOOLS;
	setIcon("emerald_axe", 0);
	setMaxStackSize(1);
	setMaxDamage(1800);
	setHandEquipped();
}

int AxeItem::getAttackDamage() {
	return 5.0F;
}

int AxeItem::getEnchantSlot() const{
	return 512;
}

int AxeItem::getEnchantValue() const{
	return 1;
}

void AxeItem::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim) {
	item->hurtAndBreak(2, victim);
}

void AxeItem::mineBlock(ItemInstance *item, BlockID blockId, int x, int y, int z, Mob *mob) {
	if(blockId == Block::mWoodPlanks->blockId
	||blockId == Block::mLog->blockId
	||blockId == Block::mChest->blockId
	||blockId == Block::mSign->blockId
	||blockId == Block::mWoodenDoor->blockId
	||blockId == Block::mLadder->blockId
	||blockId == Block::mWallSign->blockId
	||blockId == Block::mWoodPressurePlate->blockId
	||blockId == Block::mFence->blockId
	||blockId == Block::mWoodButton->blockId
	||blockId == Block::mTrappedChest->blockId
	||blockId == Block::mWoodenSlab->blockId
	||blockId == Block::mAcaciaStairs->blockId
	||blockId == Block::mDarkOakStairs->blockId
	||blockId == Block::mSpuceFenceGate->blockId
	||blockId == Block::mBirchFenceGate->blockId
	||blockId == Block::mJungleFenceGate->blockId
	||blockId == Block::mDarkOakFenceGate->blockId
	||blockId == Block::mAcaciaFenceGate->blockId
	||blockId == Block::mWoodenDoorSpruce->blockId
	||blockId == Block::mWoodenDoorBirch->blockId
	||blockId == Block::mWoodenDoorJungle->blockId
	||blockId == Block::mWoodenDoorAcacia->blockId
	||blockId == Block::mWoodenDoorDarkOak->blockId
	||blockId == Block::mWorkBench->blockId
	||blockId == Emerald::mPlanks->blockId) {
		item->hurtAndBreak(1, mob);
	} else {
		item->hurtAndBreak(2, mob);
	}
}

float AxeItem::getDestroySpeed(ItemInstance *item, Block *block) {
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
	||block == Block::mWorkBench
	||block == Emerald::mPlanks) {
		return 50.0F;
	} else {
		return 1.0F;
	}
}
