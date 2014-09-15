/// author: Viacheslav

#include <gtest/gtest.h>

#include <point.h>
#include <has_intersection.h>
#include <algorithm>

TEST(orienation, in_the_same_square)
{

    Point3D<double> a(-1, 0, 0), b(1, 0, -1), c(0, 1, 1), d(0, -1, 1), z(0.0,0.0,0.0);

    Point3D<double> p[5] = {a, b, c, d, z};

    while(std::next_permutation(p, p+5))
        EXPECT_TRUE(orientation(p[0], p[1], p[2], p[3]) == orientation_t::CG_COLLINEAR);
}
