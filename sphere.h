#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

using namespace std;

class sphere : public hittable
{
private:
    point3 center;
    double radius;

public:
    // constructor
    sphere(const point3 &center, double radius) : center(center), radius(fmax(0, radius)) {}

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h * h - a * c;

        if (discriminant < 0)
        {
            return false;
        }

        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
        auto root = (h - sqrtd) / a;

        if (!ray_t.surrounds(root))
        {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;                                    // root - value of the parameter t
        rec.p = r.at(rec.t);                             // the point visible to the camera
        vec3 outward_normal = (rec.p - center) / radius; // normal vector at the point p
        rec.set_face_normal(r, outward_normal);

        return true;
    }
};

#endif