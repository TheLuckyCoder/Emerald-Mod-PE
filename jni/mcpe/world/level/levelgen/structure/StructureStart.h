#pragma once

#include "../BoundingBox.h"
class BlockSource;
class Random;
class Level;
class CompoundTag;

class StructureStart {
public:
	virtual ~StructureStart();
	virtual bool isValid();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);

	void postProcess(BlockSource*, Random &, BoundingBox const&);
	void moveInsideHeights(Random*, int, int);
	void moveBelowSeaLevel(Random*, int);
	void load(Level*, CompoundTag*);
	void createTag(int, int);
	void calculateBoundingBox();
};