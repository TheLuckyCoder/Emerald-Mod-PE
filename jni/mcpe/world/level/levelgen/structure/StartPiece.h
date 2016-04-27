#pragma once

#include "StructurePiece.h"
class CompoundTag;
class Random;

class StartPiece
{
public:
	StartPiece();

	virtual ~StartPiece();
	virtual void getBiomeSource();
	virtual void getPieceWeights();
};