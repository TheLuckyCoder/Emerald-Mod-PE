#pragma once

class BlockSource;
class BlockPos;
class Random;
class Material;

class DeadBushFeature : public Feature{
public :
	virtual ~DeadBushFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;

	bool _isFree(Material const&) const;
};
