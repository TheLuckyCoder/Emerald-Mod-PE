#pragma once

#include "mcpe/world/entity/Mob.h"

class EmeraldCow : public Mob {
	char filler[20];
public:
	EmeraldCow(BlockSource&, float, float, float);

	virtual EntityType getEntityTypeId() const;
	virtual bool useNewAi();
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
};
