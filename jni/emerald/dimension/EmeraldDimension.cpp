#include "EmeraldDimension.h"

EmeraldDimension::EmeraldDimension(Level &level) : Dimension(level, DimensionId::EMERALD)
{
}

/*std::string EmeraldDimension::getName() const{
	return "EmeraldDimension";
}*/

void EmeraldDimension::init(){
	Dimension::init();
	
	setCeiling(true);
}

float EmeraldDimension::getFogDistanceScale() const{
	return 1;
}

int EmeraldDimension::getCloudHeight() const{
	return 500;
}

bool EmeraldDimension::mayRespawn() const{
	return true;
}

bool EmeraldDimension::hasGround() const{
	return false;
}

bool EmeraldDimension::isValidSpawn(int x, int z) const{
	return (0, 0);
}

bool EmeraldDimension::isNaturalDimension() const{
	return false;
}
