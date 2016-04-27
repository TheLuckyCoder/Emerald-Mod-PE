#pragma once

#include "../Feature.h"

class LevelChunk;
class Vec3;
class BlockSource;
class BlockPos;
class Random;

class CaveFeature : public Feature {
public:
	unsigned char data;
	
	CaveFeature();
	virtual bool isDiggable(int, int);
	virtual void addTunnel(Random&, LevelChunk&, Vec3 const&, float, float, float, int, int, float);
	virtual void addRoom(Random&, LevelChunk&, Vec3 const&);
	virtual void addFeature(LevelChunk&, BiomeSource*, Random&, int, int);

	static bool _thinSand(unsigned char*, int);
};
