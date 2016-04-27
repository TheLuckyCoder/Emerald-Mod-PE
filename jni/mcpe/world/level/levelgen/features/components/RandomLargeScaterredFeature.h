#pragma once

#include "../LargeFeature.h"

class BiomeSource;
class LevelChunk;
class ChunkPos;
class Random;

class RandomScatteredLargeFeature : public LargeFeature {
	RandomScatteredLargeFeature();

	virtual std::string getFeatureName();
	virtual bool isFeatureChunk(BiomeSource*, Random&, ChunkPos const&);
RandomScatteredLargeFeature();
	virtual void apply(ChunkSource*, LevelChunk&, BiomeSource*, Random&);
	virtual void createStructureStart(BiomeSource*, Random&, ChunkPos const&);
};
