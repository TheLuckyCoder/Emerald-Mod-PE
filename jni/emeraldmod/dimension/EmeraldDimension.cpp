#include "EmeraldDimension.h"

EmeraldDimension::EmeraldDimension(Level &level) : Dimension(level, DimensionId::EMERALD_DIMENSION)
{
}

std::string EmeraldDimension::getName() const{
	return "EMERALD";
}

void EmeraldDimension::init(){
	Dimension::init();
}

float EmeraldDimension::getFogDistanceScale() const{
	return 1.0F;
}

float EmeraldDimension::getCloudHeight() const{
	return 50.0F;
}

bool EmeraldDimension::mayRespawn() const{
	return false;
}

bool EmeraldDimension::hasGround() const{
	return false;
}

bool EmeraldDimension::isValidSpawn(int x, int z) const{
	return false;
}

bool EmeraldDimension::isNaturalDimension() const{
	return false;
}

Color EmeraldDimension::getFogColor(float) const{
	return Color::GREEN;
}

void EmeraldDimension::load(const CompoundTag&){
}

void EmeraldDimension::save(CompoundTag&){
}
