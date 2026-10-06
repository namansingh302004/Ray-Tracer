#include "ray.h"
#include "color.h"
#include "vec3.h"

#include <iostream>

using namespace std;

int main()
{
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it is greater than or equal to 1
    int image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // setting up the viewport
    // since we are settign up viewports with real-valued widths we need not check for
    // value greater than or equal to 1

    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width / image_height));
}