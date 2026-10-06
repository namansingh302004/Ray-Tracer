#ifndef RAY_H
#define RAY_H

#include "vec3.h"

using namespace std;

class ray
{
public:
    // default constructor
    ray() {}
    // parameterized constructor
    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

    // important getter() functions
    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    // now the ray function - Parameterized function P(t) = A + tb

    point3 at(double t) const
    {
        return orig + t * dir;
    }

private:
    point3 orig;
    vec3 dir;
};

#endif