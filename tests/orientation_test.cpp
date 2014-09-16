/// author: Viacheslav

#include <gtest/gtest.h>

//#include "../include/point.h"
//#include "../include/has_intersection.h"

#include <point.h>
#include <has_intersection.h>

#include <iostream>

using namespace std;

TEST(orienation, in_the_same_square)
{

    Point3D<double> a(1, 0, 0), b(0, 1, 0), c(0, 0, 1), d(0, 0, -1), z(0.0,0.0,0.0);

    EXPECT_TRUE(orientation(a, b, z, d) != orientation(a, b, z, c));
    EXPECT_TRUE(orientation(a, b, c, z) == orientation(a, b, c, d));

    EXPECT_TRUE(orientation(d, b, c, z) == orientation_t::CG_COLLINEAR);
    EXPECT_TRUE(orientation(d, b, c, z) == orientation_t::CG_COLLINEAR);

    EXPECT_TRUE(orientation(d, b, z, c) == orientation_t::CG_COLLINEAR);
    EXPECT_TRUE(orientation(d, a, z, c) == orientation_t::CG_COLLINEAR);
}
