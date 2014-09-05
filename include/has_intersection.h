/// author: Viacheslav

#ifndef HAS_INTERSECTION_H
#define HAS_INTERSECTION_H

#include "segment.h"
#include "point.h"
#include "my_orientation.h"


template<class T>
bool has_intersection(Segment3D<T> const & a, Segment3D<T> const & b)
{
    Point3D<T> p[5] = {a[0], a[1], b[0], b[1], Point3d(0.0,0.0,0.0)};


    orientation_t ab[2];
    for (size_t l = 0; l != 2; ++l)
       ab[l] = orientation(a[0], a[1], b[l]);


    if (ab[0] == ab[1] && ab[0] == CG_COLLINEAR)
    {
	// TODO: здесь вроде бага
        // случай когда на одной большой окружности.
        // провести через одни плоскость и посмотреть, с какой стороны второй от нее.

        // r(P) = (n1 x AB)*AP;
        Point3d n1(p[0].y*p[1].z - p[0].z*p[1].y,  -p[0].x*p[1].z + p[0].z*p[1].x, p[0].x*p[1].y - p[0].y*p[1].x);
        //  i  j  k
        // ax ay az
        // bx by bz
        Point3d ab(p[0].x-p[1].x, p[0].y-p[1].y, p[0].z-p[1].z);

        orientation_t AC, AD;
        AC = orientation(n1, ab, Point3d(p[2].x-p[0].x, p[2].y-p[0].y, p[2].z-p[0].z), 21);
        AD = orientation(n1, ab, Point3d(p[3].x-p[0].x, p[3].y-p[0].y, p[3].x-p[0].z), 21);


        if(AC==AD && AC==CG_RIGHT)
            return false;
        else
            return true;
    }



    orientation_t t1 = orientation (p[0]-p[3], p[1]-p[3], p[2]-p[3]);  // 0 1 2 - 3
    orientation_t t2 = orientation (p[0], p[1],p[2]);                  // 0 1 2 - O

    orientation_t t3 = orientation (p[0]-p[2], p[1]-p[2], p[3]-p[2]);   // 0 1 3 - 2
    orientation_t t4 = orientation (p[0], p[1], p[3]);

    orientation_t t5 = orientation (p[0]-p[1], p[2]-p[1], p[3]-p[1]);   // 0 2 3 - 1
    orientation_t t6 = orientation (p[0], p[2], p[3]);

    orientation_t t7 = orientation (p[1]-p[0], p[2]-p[0], p[3]-p[0]);   // 1 2 3 - 0
    orientation_t t8 = orientation (p[1], p[2], p[3]);

    if(((t1 == t1) && (t3 == t4) && (t5 == t6) && (t7 == t8)))
    {
        return false;
    }



    // по одну сторону - не пересекаются.
    if (ab[0] == ab[1])
       return false;


    // еще шанс:
    for (size_t l = 0; l != 2; ++l)
       ab[l] = orientation(b[0], b[1], a[l]);

    // по одну сторону
    return ab[0] != ab[1];
}


#endif // HAS_INTERSECTION_H
