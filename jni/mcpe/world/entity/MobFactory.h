#pragma once

#include <memory>

#include "EntityType.h"
#include "Mob.h"
#include "../level/BlockSource.h"
#include "../phys/Vec3.h"

struct MobFactory {
	static std::unique_ptr<Mob> CreateMob(EntityType, BlockSource&, const Vec3&);
};

