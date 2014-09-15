/// author: Viacheslav

#include <gtest/gtest.h>

#include <point.h>
#include <has_intersection.h>
#include <segment.h>

const double kRadius = 200;

const double PI = 3.141592653589;
const double ClEquator = PI/2;
const double Grinvich = 0.0;

const double EightOffset = M_PI/4;
const double QuaterOffset = M_PI/2;
const double HalfOffset = M_PI;

const double M45 = PI/4;
const double M135 = 3*PI/4;

const Point3d N = getDecart(0.0, Grinvich, kRadius);
const Point3d S = getDecart(PI, Grinvich, kRadius);


TEST(has_intersection, segment_segment)
{

   Segment3D<double> s[] =
   {
      Segment3d(getDecart(0.0,0.0,kRadius), getDecart(PI/2, PI/2, kRadius)),
      Segment3d(getDecart(PI / 3, 0.0, kRadius), getDecart(PI / 3, PI / 2+0.1, kRadius)),
      Segment3d(getDecart(2*PI / 3, 0.0, kRadius), getDecart(2*PI / 3, PI / 2+0.1,kRadius)),

      Segment3d(N, S), // гринвичский меридиан
      Segment3d(getDecart(M45, Grinvich + EightOffset, kRadius),getDecart(M45, Grinvich+ QuaterOffset, kRadius)), // сбоку от гринвича
      Segment3d(getDecart(M135, Grinvich - EightOffset, kRadius),getDecart(M135, Grinvich + EightOffset, kRadius)),  // через гринвич

      Segment3d(getDecart(M45, Grinvich - EightOffset, kRadius),getDecart(M135, Grinvich+ QuaterOffset, kRadius)), // LR
      Segment3d(getDecart(M45, Grinvich + EightOffset, kRadius),getDecart(M135, Grinvich - EightOffset, kRadius)),  // RL
      Segment3d(getDecart(M45, Grinvich + EightOffset+PI, kRadius),getDecart(M135, Grinvich - EightOffset+PI, kRadius)),  // RL с другой стороны
      Segment3d(getDecart(M135, Grinvich + EightOffset+PI, kRadius),getDecart(M45, Grinvich - EightOffset+PI, kRadius)),  // LR с другой стороны

      Segment3d(N, getDecart(M45, 0.0, kRadius)),
      Segment3d(getDecart(M135, 0.0, kRadius), S)
   };



   EXPECT_TRUE(has_intersection(s[0], s[1]));
   EXPECT_TRUE(has_intersection(s[1], s[0]));
   EXPECT_FALSE(has_intersection(s[0], s[2]));
   EXPECT_FALSE(has_intersection(s[1], s[2]));


   EXPECT_FALSE(has_intersection(s[3], s[4]));
   EXPECT_TRUE(has_intersection(s[3], s[5]));

   EXPECT_TRUE(has_intersection(s[6], s[7]));
   EXPECT_TRUE(has_intersection(s[7], s[6]));

   EXPECT_TRUE(has_intersection(s[6], s[3]));
   EXPECT_TRUE(has_intersection(s[7], s[3]));

   EXPECT_FALSE(has_intersection(s[8], s[7]));
   EXPECT_FALSE(has_intersection(s[8], s[6]));
   EXPECT_FALSE(has_intersection(s[8], s[0]));

   EXPECT_FALSE(has_intersection(s[7], s[9])); // случай с тетраэдром
   EXPECT_FALSE(has_intersection(s[10], s[11])); // на меридиане


   // на меридиане
    Segment3d t[] =
    {
        Segment3d(getDecart(ClEquator, Grinvich, kRadius),getDecart(ClEquator, Grinvich+ QuaterOffset, kRadius)),
        Segment3d(getDecart(ClEquator, Grinvich + HalfOffset, kRadius),getDecart(ClEquator, Grinvich +HalfOffset+QuaterOffset, kRadius)),
        Segment3d(getDecart(ClEquator, Grinvich - QuaterOffset, kRadius),getDecart(ClEquator, Grinvich + QuaterOffset, kRadius)),
        Segment3d(getDecart(ClEquator, Grinvich - EightOffset, kRadius),getDecart(ClEquator, Grinvich + EightOffset, kRadius))
    };



    EXPECT_TRUE(has_intersection(t[0], t[2]));
    EXPECT_TRUE(has_intersection(t[3], t[0]));
    EXPECT_FALSE(has_intersection(t[0], t[1]));
    EXPECT_FALSE(has_intersection(t[1], t[4]));
}
