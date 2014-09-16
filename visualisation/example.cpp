#include "example.h"

#include <point.h>
#include <has_intersection.h>
#include <segment.h>

const double PI = 3.141592653589;
const double ClEquator = PI/2;
const double Grinvich = 0.0;

const double EightOffset = M_PI/4;
const double QuaterOffset = M_PI/2;
const double HalfOffset = M_PI;

const double M45 = PI/4;
const double M135 = 3*PI/4;


Example::Example()
{
    setLineSegments(20);
    setSpaceSegments(35);

    setRadius(200);

    const double kRadius = getRadius();
    const Point3d N = getDecart(0.0, Grinvich, kRadius);
    const Point3d S = getDecart(PI, Grinvich, kRadius);


    // просто отрезки (в том числе в разных полушариях)
    // красные - свободные
    // зеленые - пересекаются

    Segment3d s[] =
    {
        Segment3d(getDecart(M135, Grinvich - EightOffset, kRadius),getDecart(M135, Grinvich + EightOffset, kRadius)),  // через гринвич
        Segment3d(getDecart(M45, Grinvich - EightOffset, kRadius),getDecart(M135, Grinvich+ QuaterOffset, kRadius)), // LR
        Segment3d(getDecart(M45, Grinvich + EightOffset, kRadius),getDecart(M135, Grinvich - EightOffset, kRadius)),  // RL
        Segment3d(getDecart(M45, Grinvich + EightOffset+PI, kRadius),getDecart(M135, Grinvich - EightOffset+PI, kRadius)),  // RL с другой стороны
    };

    int crossS[4] ={0};


    for(int i=0; i<4; ++i)
    {
        for(int j=i+1; j<4; ++j)
        {
            if(has_intersection(s[i], s[j]))
            {
                crossS[i]++;
                crossS[j]++;
            }
        }
    }

    for(int i=0; i<4; ++i)
   {
       QColor c;
       if(crossS[i])
       {
           c = QColor::fromRgb(0x0, 0xFF, 0);
       }
       else
       {
           c = QColor::fromRgb(0xFF, 0x0, 0);
       }
       Point3d a0 = getPolar(s[i][0]);
       Point3d a1 = getPolar(s[i][1]);
       addLine(Vector2D(a0.y, a0.z), Vector2D(a1.y, a1.z), c);
   }

 //------------------------------

    // отрезки на экваторе. со старыми никак не проверяются. это "другие" отрезки.
    // белые - свободные
    // синий - пересекаются
    Segment3d t[] =
    {
        Segment3d(getDecart(ClEquator, Grinvich, kRadius),getDecart(ClEquator, Grinvich+ QuaterOffset, kRadius)),
        Segment3d(getDecart(ClEquator, Grinvich + HalfOffset, kRadius),getDecart(ClEquator, Grinvich +HalfOffset+QuaterOffset, kRadius)),
        Segment3d(getDecart(ClEquator, Grinvich - EightOffset, kRadius),getDecart(ClEquator, Grinvich + EightOffset, kRadius))
    };



    int crossT[3] = {0};

    for(int i=0; i<3; ++i)
    {
        for(int j=i+1; j<3; ++j)
        {
            if(has_intersection(t[i], t[j]))
            {
                crossT[i]++;
                crossT[j]++;
            }
        }
    }

   for(int i=0; i<3; ++i)
   {
       QColor c;
       if(crossT[i])
       {
           c = QColor::fromRgb(0x0, 0x0, 0xFF);
       }
       else
       {
           c = QColor::fromRgb(0xFF, 0xFF, 0xFF);
       }
       Point3d a0 = getPolar(t[i][0]);
       Point3d a1 = getPolar(t[i][1]);
       addLine(Vector2D(a0.y, a0.z), Vector2D(a1.y, a1.z), c);
   }



}
