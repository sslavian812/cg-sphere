#pragma once

#include <visualization.h>
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

const double R = 200;



class Example : public Visualization
{
public:

//    Example()
//    {
//        setLineSegments(20);
//        setSpaceSegments(35);

//        setRadius(R);

//        Segment3D<double> s[] =
//        {
//            //Segment3d(getDecart(PI/3,0.0+0.1,R), getDecart(PI/3, PI/4+0.1, R)),
//           // Segment3d(getDecart(2*PI/3,PI,R+0.1), getDecart(2*PI/3, PI+PI/4+0.1, R)),


////            Segment3d(getDecart(0.0,0.0,R), getDecart(2*PI/3, 0.0, R)),
////            Segment3d(getDecart(PI/3,0.0,R), getDecart(3*PI/4, 0.0, R))

//            Segment3d(getDecart(0.0,0.0,R), getDecart(3*PI/4, 0.0, R)),
//            Segment3d(getDecart(PI/3,0.0,R), getDecart(2*PI/4, 0.0, R))
//        };

//        const int SIZE =2;
//        int crossS[SIZE] ={0};


//        for(int i=0; i<SIZE; ++i)
//        {
//            for(int j=i+1; j<SIZE; ++j)
//            {
//                if(has_intersection(s[i], s[j]))
//                {
//                    crossS[i]++;
//                    crossS[j]++;
//                }
//            }
//        }

//       for(int i=0; i<SIZE; ++i)
//       {
//           QColor c;
//           if(crossS[i])
//           {
//               c = QColor::fromRgb(0x0, 0xFF, 0);
//           }
//           else
//           {
//               c = QColor::fromRgb(0xFF, 0x0, 0);
//           }
//           Point3d a0 = getPolar(s[i][0]);
//           Point3d a1 = getPolar(s[i][1]);
//           addLine(Vector2D(a0.y, a0.z), Vector2D(a1.y, a1.z), c);
//       }

//   }
    Example()
    {
        setLineSegments(20);
        setSpaceSegments(35);

        setRadius(200);

        const double R = getRadius();
        const Point3d N = getDecart(0.0, Grinvich, R);
        const Point3d S = getDecart(PI, Grinvich, R);


        // просто отрезки (в том числе в разных полушариях)
        // красные - свободные
        // зеленые - пересекаются

        Segment3d s[] =
        {
            Segment3d(getDecart(M135, Grinvich - EightOffset, R),getDecart(M135, Grinvich + EightOffset, R)),  // через гринвич
            Segment3d(getDecart(M45, Grinvich - EightOffset, R),getDecart(M135, Grinvich+ QuaterOffset, R)), // LR
            Segment3d(getDecart(M45, Grinvich + EightOffset, R),getDecart(M135, Grinvich - EightOffset, R)),  // RL
            Segment3d(getDecart(M45, Grinvich + EightOffset+PI, R),getDecart(M135, Grinvich - EightOffset+PI, R)),  // RL с другой стороны
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
            Segment3d(getDecart(ClEquator, Grinvich, R),getDecart(ClEquator, Grinvich+ QuaterOffset, R)),
            Segment3d(getDecart(ClEquator, Grinvich + HalfOffset, R),getDecart(ClEquator, Grinvich +HalfOffset+QuaterOffset, R)),
            Segment3d(getDecart(ClEquator, Grinvich - EightOffset, R),getDecart(ClEquator, Grinvich + EightOffset, R))
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

};
