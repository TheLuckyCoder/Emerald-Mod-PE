#pragma once

#include "Feature.h"
class BlockSource;
class BlockPos;
class Random;

class LakeFeature : public Feature {
public:
	BlockID id; // 9

	LakeFeature(BlockID);
	LakeFeature(BlockID, BlockID);

	virtual ~LakeFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;

	void _check(const BlockPos&, bool*) const;
};
