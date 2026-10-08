#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

// C++ usings

using std::make_shared;
using std::shared_ptr;

// Some constants that we will use
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// simple utility functions we might need

inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180.0;
}

inline double random_double()
{
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
    return min + (max - min) * random_double();
}

// common headers we made so far and used repeatedly

#include "color.h"
#include "interval.h"
#include "vec3.h"
#include "ray.h"

#endif