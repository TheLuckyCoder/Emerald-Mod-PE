#pragma once

#include "Entity.h"
#include "EntityType.h"

class EntityClassTree
{
public:
	static bool isInstanceOf(Entity const&,EntityType);
};

