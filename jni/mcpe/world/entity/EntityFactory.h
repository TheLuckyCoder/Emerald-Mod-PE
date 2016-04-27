#pragma once

#include <memory>

#include "Enity.h"
#include "EntityType.h"
#include "../level/BlockSource.h"

struct EntityFactory {
	static std::unique_ptr<Entity> CreateEntity(EntityType, BlockSource&);
};

