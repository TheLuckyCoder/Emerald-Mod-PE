#include "SlabBlock.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/leveledit.h"
#include "../Emerald.h"

SlabBlock::SlabBlock(int blockId) : Block("emeraldSlab", blockId, "emerald_block", Material::getMaterial(MaterialType::METAL))
{
	setDestroyTime(2.0F);
	setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	setSolid(false);
	setVisualShape({0.0F, 0.0F, 0.0F}, {1.0F, 0.5F, 1.0F});
	creativeCategory = 1;
}

bool SlabBlock::use(Player& player, const BlockPos& pos){	
	//if(player->region.getBlockID(pos).id == Emerald::mSlab->blockId) {
		//player->region.setBlockAndData(pos, {Block::mEmeraldBlock->blockId, 0}, 3);
	//} else {
		return Block::use(player, pos);
	//}
}
