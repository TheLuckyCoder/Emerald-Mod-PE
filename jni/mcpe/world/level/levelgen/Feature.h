#pragma once

#include <string>

class BlockSource;
class BlockPos;
class Random;

#include "../../../CommonTypes.h"

class Feature {
public:
	unsigned char updateNotify; // 4
	bool isManuallyPlaced; // 8

	Feature(bool);

	virtual ~Feature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
	virtual bool place(BlockSource&, const BlockPos&, Random&, int) const = 0;
	virtual bool placeFlower(BlockSource&, BlockPos const&, FullBlock, Random&) const;
	virtual std::string getFeatureName();
	virtual bool isDiggable(int, int);
	virtual void addTunnel(Random&, LevelChunk&, Vec3 const&, float, float, float, int, int, float);
	virtual void addRoom(Random&, LevelChunk&, Vec3 const&);
	virtual void addFeature(LevelChunk&, BiomeSource*, Random&, int, int);
	virtual bool isFeatureChunk(BiomeSource*, Random&, ChunkPos const&);
	virtual void apply(ChunkSource*, LevelChunk&, BiomeSource*, Random&);
	virtual void createStructureStart(BiomeSource*, Random&, ChunkPos const&);
	virtual void getStructureAt(int, int, int);
	virtual bool place(BlockSource&, const BlockPos&, Random&, int, int) const = 0;
	
	bool _getManuallyPlaced() const;
	void _placeBlock(BlockSource&, const BlockPos&, const FullBlock&) const;
	void _setBlockAndData(BlockSource&, const BlockPos&, const FullBlock&) const;
};
