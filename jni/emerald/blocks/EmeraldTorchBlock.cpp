#include "EmeraldTorchBlock.h"
#include "mcpe/CreativeItemCategory.h"

EmeraldTorchBlock::EmeraldTorchBlock(int blockId) : TorchBlock("emeraldTorch", blockId, "emerald_block")
{
	//setDestroyTime(2.0F);
	//setExplodeable(8.0F);
	setMapColor(Color::GREEN);
	creativeCategory = CreativeItemCategory::BLOCKS;
}
