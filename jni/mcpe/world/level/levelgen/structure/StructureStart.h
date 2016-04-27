#pragma once

#include "../BoundingBox.h"
class BlockSource;
class Random;
class Level;
class CompoundTag;

class StructureStart {
public:
	virtual ~StructureStart();

	void StructureStart::postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	void postProcess(BlockSource*, Random &, BoundingBox const&);
	void moveInsideHeights(Random*, int, int);
	void moveBelowSeaLevel(Random*, int);
	void load(Level*, CompoundTag*);
	bool isValid();
	void createTag(int, int);
	void calculateBoundingBox();

	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};