#pragma once

#include "../Feature.h"

class BiomeSource;
class LevelChunk;
class ChunkPos;
class Random;

class LargeFeature : public Feature {
public:
	LargeFeature();

	virtual std::string getFeatureName();
	virtual bool isFeatureChunk(BiomeSource*, Random&, ChunkPos const&);
	virtual void apply(ChunkSource*, LevelChunk&, BiomeSource*, Random&);
	virtual void createStructureStart(BiomeSource*, Random&, ChunkPos const&);
};
