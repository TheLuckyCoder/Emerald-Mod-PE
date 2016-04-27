#pragma once

#include "../CaveFeature.h"

class LevelChunk;
class BiomeSource;
class Vec3;
class BlockSource;
class BlockPos;
class Random;

class LargeCaveFeature : public CaveFeature {
public:
	unsigned char data;

	virtual ~LargeCaveFeature();
	
	LargeCaveFeature();
	bool isDiggable(int, int);
	void addTunnel(Random&, LevelChunk&, Vec3 const&, float, float, float, int, int, float);
	void addRoom(Random&, LevelChunk&, Vec3 const&);
	void addFeature(LevelChunk&, BiomeSource*, Random&, int, int);

	bool _thinSand(unsigned char*, int);
};
