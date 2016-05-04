#pragma once

#include <vector>

class BiomeSource;
class CompoundTag;
class Random;
class PieceWeight;

class StartPiece {
public:
	StartPiece(BiomeSource*, int, Random&, int, int, std::vector<PieceWeight, std::allocator<PieceWeight>>&, int);

	virtual ~StartPiece();
	//virtual void addChildren(); //It's to hard to demangle
	void getPieceWeights();
	void getBiomeSource();
};