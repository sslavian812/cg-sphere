/// author: Viacheslav

#include <gtest/gtest.h>

#include <point.h>
#include <has_intersection.h>
#include <segment.h>

const double R = 200;

const double PI = 3.141592653589;
const double ClEquator = PI/2;
const double Grinvich = 0.0;

const double EightOffset = M_PI/4;
const double QuaterOffset = M_PI/2;
const double HalfOffset = M_PI;

const double M45 = PI/4;
const double M135 = 3*PI/4;

const Point3d N = getDecart(0.0, Grinvich, R);
const Point3d S = getDecart(PI, Grinvich, R);


TEST(has_intersection, simple_case)
{
    Segment3D<double> s[] =
    {
        Segment3d(getDecart(PI/3,0.0+0.1,R), getDecart(PI/3, PI/4+0.1, R)),
        Segment3d(getDecart(0.0,0.0,R), getDecart(2*PI/3, 0.0, R)),

        Segment3d(getDecart(PI/3, -PI/2,R), getDecart(PI/3, PI/2, R)),
        Segment3d(getDecart(0.0,0.0,R), getDecart(2*PI/3, 0.0, R))
    };

    EXPECT_FALSE(has_intersection(s[0], s[1]));
    EXPECT_TRUE(has_intersection(s[2], s[3]));
}




TEST(has_intersection, different_hemispheres)
{
    Segment3D<double> s[] =
    {
       Segment3d(getDecart(0.0,0.0,R), getDecart(PI/3, PI/3, R)),
       Segment3d(getDecart(PI,PI,R), getDecart(PI+PI/3, -PI/3, R)),


       Segment3d(getDecart(PI/2, 0.0, R), getDecart(2*PI/3, PI/6, R)),
       Segment3d(getDecart(PI/2,PI,R), getDecart(PI/6, PI+PI/6, R)),

       Segment3d(getDecart(PI/3,0.0+0.1,R), getDecart(PI/3, PI/4+0.1, R)),
       Segment3d(getDecart(2*PI/3,PI,R+0.1), getDecart(2*PI/3, PI+PI/4+0.1, R))
    };

    EXPECT_FALSE(has_intersection(s[0], s[1]));
    EXPECT_FALSE(has_intersection(s[2], s[3]));
    EXPECT_FALSE(has_intersection(s[4], s[5]));

}


TEST(has_intersection, on_the_same_radius)
{
    Segment3D<double> s[] =
    {
        // does not intersect
        Segment3d(getDecart(PI/3,0.0,R), getDecart(PI/3, PI/4, R)),
        Segment3d(getDecart(PI/3,PI,R), getDecart(PI/3, PI+PI/4, R)),


        // overlay
        Segment3d(getDecart(0.0,0.0,R), getDecart(2*PI/3, 0.0, R)),
        Segment3d(getDecart(PI/3,0.0,R), getDecart(3*PI/4, 0.0, R)),

        // one contains the other
        Segment3d(getDecart(0.0,0.0,R), getDecart(3*PI/4, 0.0, R)),
        Segment3d(getDecart(PI/3,0.0,R), getDecart(2*PI/4, 0.0, R))

    };

    EXPECT_FALSE(has_intersection(s[0], s[1]));
    EXPECT_TRUE(has_intersection(s[2], s[3]));
    EXPECT_TRUE(has_intersection(s[4], s[5]));
}




//TEST(has_intersection, segment_segment)
//{

//   Segment3D<double> s[] =
//   {
//      Segment3d(getDecart(0.0,0.0,R), getDecart(PI/2, PI/2, R)),
//      Segment3d(getDecart(PI / 3, 0.0, R), getDecart(PI / 3, PI / 2+0.1, R)),
//      Segment3d(getDecart(2*PI / 3, 0.0, R), getDecart(2*PI / 3, PI / 2+0.1,R)),

//      Segment3d(N, S), // гринвичский меридиан
//      Segment3d(getDecart(M45, Grinvich + EightOffset, R),getDecart(M45, Grinvich+ QuaterOffset, R)), // сбоку от гринвича
//      Segment3d(getDecart(M135, Grinvich - EightOffset, R),getDecart(M135, Grinvich + EightOffset, R)),  // через гринвич

//      Segment3d(getDecart(M45, Grinvich - EightOffset, R),getDecart(M135, Grinvich+ QuaterOffset, R)), // LR
//      Segment3d(getDecart(M45, Grinvich + EightOffset, R),getDecart(M135, Grinvich - EightOffset, R)),  // RL
//      Segment3d(getDecart(M45, Grinvich + EightOffset+PI, R),getDecart(M135, Grinvich - EightOffset+PI, R)),  // RL с другой стороны
//      Segment3d(getDecart(M135, Grinvich + EightOffset+PI, R),getDecart(M45, Grinvich - EightOffset+PI, R)),  // LR с другой стороны

//      Segment3d(N, getDecart(M45, 0.0, R)),
//      Segment3d(getDecart(M135, 0.0, R), S)
//   };



//   EXPECT_TRUE(has_intersection(s[0], s[1]));
//   EXPECT_TRUE(has_intersection(s[1], s[0]));
//   EXPECT_FALSE(has_intersection(s[0], s[2]));
//   EXPECT_FALSE(has_intersection(s[1], s[2]));


//   EXPECT_FALSE(has_intersection(s[3], s[4]));
//   EXPECT_TRUE(has_intersection(s[3], s[5]));

//   EXPECT_TRUE(has_intersection(s[6], s[7]));
//   EXPECT_TRUE(has_intersection(s[7], s[6]));

//   EXPECT_TRUE(has_intersection(s[6], s[3]));
//   EXPECT_TRUE(has_intersection(s[7], s[3]));

//   EXPECT_FALSE(has_intersection(s[8], s[7]));
//   EXPECT_FALSE(has_intersection(s[8], s[6]));
//   EXPECT_FALSE(has_intersection(s[8], s[0]));

//   EXPECT_FALSE(has_intersection(s[7], s[9])); // случай с тетраэдром
//   EXPECT_FALSE(has_intersection(s[10], s[11])); // на меридиане


//   // на меридиане
//    Segment3d t[] =
//    {
//        Segment3d(getDecart(ClEquator, Grinvich, R),getDecart(ClEquator, Grinvich+ QuaterOffset, R)),
//        Segment3d(getDecart(ClEquator, Grinvich + HalfOffset, R),getDecart(ClEquator, Grinvich +HalfOffset+QuaterOffset, R)),
//        Segment3d(getDecart(ClEquator, Grinvich - QuaterOffset, R),getDecart(ClEquator, Grinvich + QuaterOffset, R)),
//        Segment3d(getDecart(ClEquator, Grinvich - EightOffset, R),getDecart(ClEquator, Grinvich + EightOffset, R))
//    };



//    EXPECT_TRUE(has_intersection(t[0], t[2]));
//    EXPECT_TRUE(has_intersection(t[3], t[0]));
//    EXPECT_FALSE(has_intersection(t[0], t[1]));
//    EXPECT_FALSE(has_intersection(t[1], t[4]));
//}
