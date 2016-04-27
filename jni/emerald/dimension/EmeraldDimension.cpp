#include "EmeraldDimension.h"

EmeraldDimension::EmeraldDimension(Level &level) : Dimension(level, EMERALD)
{
}

const std::string& EmeraldDimension::getName() const{
	return "EmeraldDimension";
}

void EmeraldDimension::init(){
	Dimension::init();
	
	setCeiling(true);
}

float EmeraldDimension::getFogDistanceScale() const{
	return 1;
}

int EmeraldDimension::getCloudHeight() const{
	return 512;
}

bool EmeraldDimension::mayRespawn() const{
	return true;
}

bool EmeraldDimension::hasGround() const{
	return false;
}

bool EmeraldDimension::isValidSpawn(int x, int z) const{
	x = 0;
	z = 0;
}
