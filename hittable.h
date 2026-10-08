#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

using namespace std;

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    // this is a function to determine what part of the object the ray is hitting
    // is it the inner part or the outer one?
    void set_face_normal(const ray &r, const vec3 &outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};

#endif