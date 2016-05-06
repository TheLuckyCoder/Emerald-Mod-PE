#include "EmeraldCow.h"

EmeraldCow::EmeraldCow(BlockSource& region, float x, float y, float z) : Mob(region) {
	rendererId = EntityRendererId::COW;
	setPos({x, y, z});
	_init();
}

EntityType EmeraldCow::getEntityTypeId() const {
	return EntityType::COW_EMERALD;
}

bool EmeraldCow::useNewAi(){
	return true;
}

void EmeraldCow::readAdditionalSaveData(const CompoundTag*) {
}

void EmeraldCow::addAdditionalSaveData(CompoundTag*) {
}
