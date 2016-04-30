#pragma once

#include <string>
#include <memory>
#include <vector>

#include "dimension/Dimension.h"
#include "Level.h"

class ChunkViewSource;
class ChunkPos;
class LoadMode;

class ChunkSource
{
public:
    Level* level;
	Dimension* dimension;

    ChunkSource(Level*, Dimension*, int);
	ChunkSource(std::unique_ptr<ChunkSource, std::default_delete<ChunkSource>>);
	ChunkSource(ChunkSource&);

	virtual void loadChunk(LevelChunk&);
	virtual void compact();
	virtual void waitDiscardFinished();
	virtual void postProcess(ChunkViewSource&);
	virtual void getExistingChunk(const ChunkPos &);
	virtual void requestChunk(const ChunkPos&, LoadMode mode);
	virtual void releaseChunk(LevelChunk &chunk);
	virtual void getStoredChunks() const;
	virtual void getStoredChunks();

	Level* getLevel() const;
	DimensionId* getDimension() const;
};
