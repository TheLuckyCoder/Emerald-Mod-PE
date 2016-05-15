#pragma once

#include "../StructureStart.h"
class BiomeSource;

class NetherBridgeStart : public StructureStart
{
public:
	NetherBridgeStart();
	NetherBridgeStart(BiomeSource&, Random&, int, int);
};
