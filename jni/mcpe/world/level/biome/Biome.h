#pragma once

class TreeFeature;

struct Biome {
	int getGrassColor(const BlockPos &);
	TreeFeature* getTreeFeature(Random*);
};