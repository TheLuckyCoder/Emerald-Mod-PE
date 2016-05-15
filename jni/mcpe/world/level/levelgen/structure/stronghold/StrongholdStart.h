#pragma once

#include "../StructureStart.h"
class BiomeSource;

class StrongholdStart : public StructureStart
{
public:
	StrongholdStart(BiomeSource*, Random&, int, int);
	
	virtual ~StrongholdStart();
	virtual bool isValid() const;
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
