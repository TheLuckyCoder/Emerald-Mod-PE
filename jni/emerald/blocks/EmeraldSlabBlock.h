#pragma once

#include "mcpe/world/level/block/SlabBlock.h"

class EmeraldSlabBlock : public SlabBlock
{
public:
	TextureUVCoordinateSet emeraldTex;

	EmeraldSlabBlock(int blockId);
	virtual bool use(Player&, const BlockPos&);
	virtual const TextureUVCoordinateSet& getTexture(signed char);
};
