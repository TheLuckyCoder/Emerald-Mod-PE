#pragma once

#include "mcpe/world/level/dimension/Dimension.h"

class EmeraldDimension : public Dimension{
public:
	EmeraldDimension(Level &level);

	virtual void init();

	virtual std::string getName() const = 0;
	virtual float getFogDistanceScale() const;
	virtual float getCloudHeight() const;
	virtual bool mayRespawn() const;
	virtual bool hasGround() const;
	virtual bool isValidSpawn(int, int) const;
	virtual bool isNaturalDimension() const;
	virtual Color getFogColor(float) const;
};
