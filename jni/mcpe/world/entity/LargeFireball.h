#pragma once

#include "Fireball.h"

struct LargeFireball : public Fireball {
    char cfiller[0x188 - 333];
    LargeFireball(BlockSource &);
    LargeFireball(Mob&, Vec3 const&);
    LargeFireball(BlockSource &, Vec3 const&, Vec3 const&);
    virtual ~LargeFireball();
    virtual int getEntityTypeId();
    virtual void* readAdditionalSaveData(CompoundTag const&);
    virtual void* addAdditionalSaveData(CompoundTag&);
};