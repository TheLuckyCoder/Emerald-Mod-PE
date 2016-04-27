#pragma once

#include "../StructureFeature.h"

class BiomeStructure;
class Random;
class ChunkPos;

class VillageFeature : public StructureFeature {
public:
	VillageFeature();

	virtual ~VillageFeature();
	virtual std::string getFeatureName();
	virtual bool isFeatureChunk(BiomeSource*, Random&, ChunkPos const&);
	virtual void createStructureStart(BiomeSource*, Random&, ChunkPos const&);
};
