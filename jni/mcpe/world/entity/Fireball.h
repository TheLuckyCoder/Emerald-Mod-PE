#pragma once

#inxlude "Entity"
class Vec3;

struct Fireball : public Entity {
    void _setPower(Vec3 const&);
};