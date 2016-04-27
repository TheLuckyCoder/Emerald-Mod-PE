#pragma once

#include "../Feature.h"

class LevelChunk;
class BiomeSource;
class BlockSource;
class Random;

class StructureFeature : public Feature {
public:
	virtual ~StructureFeature();
	
	virtual void addFeature(LevelChunk&, BiomeSource*, Random&, int, int);
	virtual void getStructureAt(int, int, int);
	virtual bool isInsideFeature(int, int, int);
	virtual bool isInsideBoundingFeature(int, int, int);
	virtual void postProcess(BlockSource*, Random&, int, int);
	virtual void postProcessMobsAt(BlockSource*, int, int, Random&);
};
