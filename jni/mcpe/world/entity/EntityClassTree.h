#pragma once

#include "EntityType.h"
class Entity;

struct EntityClassTree {
  static bool isOfType(EntityType, EntityType);
  static bool isMob(Entity const&);
  static bool isMob(EntityType);
  static bool isHangingEntity(Entity const&);
  static bool isItemEntity(Entity const&);
  static bool isPlayer(Entity const&);
  static int getMobCategory(EntityType);
  static bool isInstanceOf(Entity const&, EntityType);
  static bool isTypeInstanceOf(EntityType, EntityType);
};
