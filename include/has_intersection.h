/// author: Viacheslav

#pragma once

#include "segment.h"
#include "point.h"
#include "my_orientation.h"


using std::next_permutation;


template<class T>
bool has_intersection(Segment3D<T> const & sa, Segment3D<T> const & sb)
{
 //  Point3D<T> p[5] = {sa[0], sa[1], sb[0], sb[1], Point3d(0.0,0.0,0.0)};
    Point3D<T> a(sa[0]), b(sa[1]), c(sb[0]), d(sb[1]), z(0.0,0.0,0.0);

    // p = {a,b,c,d,z}


/*
    orientation_t ab[2];
    ab[0] = orientation(a, b, c, z);
    ab[0] = orientation(a, b, d, z);


    if (ab[0] == ab[1] && ab[0] == CG_COLLINEAR)
    {
        // segments are on one big circle

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
        AC = orientation(n1, ab, Point3d(p[2].x-p[0].x, p[2].y-p[0].y, p[2].z-p[0].z), 21); // n1, ab, (p[2]-p[0])
        AD = orientation(n1, ab, Point3d(p[3].x-p[0].x, p[3].y-p[0].y, p[3].x-p[0].z), 21); // n1, ab, (p[3]-p[0])


        if(AC==AD && AC==CG_RIGHT)
            return false;
        else
            return true;
    }
*/




    // сложить в цикл.

    // std::next_permutation



//    orientation_t t1 = orientation (p[0]-p[3], p[1]-p[3], p[2]-p[3]);  // 0 1 2 - 3
//    orientation_t t2 = orientation (p[0], p[1],p[2]);                  // 0 1 2 - O.O.O
//
//    orientation_t t3 = orientation (p[0]-p[2], p[1]-p[2], p[3]-p[2]);   // 0 1 3 - 2
//    orientation_t t4 = orientation (p[0], p[1], p[3]);
//
//    orientation_t t5 = orientation (p[0]-p[1], p[2]-p[1], p[3]-p[1]);   // 0 2 3 - 1
//    orientation_t t6 = orientation (p[0], p[2], p[3]);
//
//    orientation_t t7 = orientation (p[1]-p[0], p[2]-p[0], p[3]-p[0]);   // 1 2 3 - 0
//    orientation_t t8 = orientation (p[1], p[2], p[3]);

    orientation_t t1 = orientation (a, b, c, d);  // 0 1 2 - 3
    orientation_t t2 = orientation (a, b, c, z);                  // 0 1 2 - O.O.O

    orientation_t t3 = orientation (b, c, d, a);   // 0 1 3 - 2
    orientation_t t4 = orientation (b, c, d, z);

    orientation_t t5 = orientation (a, b, d, c);   // 0 2 3 - 1
    orientation_t t6 = orientation (a, b, d, z);

    orientation_t t7 = orientation (a, d, c, b);
    orientation_t t8 = orientation (a, d, c, z);


    if(((t1 == t1) && (t3 == t4) && (t5 == t6) && (t7 == t8)))
    {
        // in different hemispheres
        return false;
    }

    // in same hemispheres


    orientation_t ab[2];
    ab[0] = orientation(a, b, c, z);
    ab[1] = orientation(a, b, d, z);


    if (ab[0] == ab[1] && ab[0] == CG_COLLINEAR)
    {
        // segments are on one big circle

        Point3d n1(a.y*b.z - a.z*b.y, -(a.x*b.z + a.z*b.x), a.x*b.y - a.y*b.x); // ON1
        //  i  j  k
        // ax ay az
        // bx by bz

        orientation_t C, D, Z;
        C = orientation(n1, a, b, c); // 21
        D = orientation(n1, a, b, d); // 21
        Z = orientation(n1, a, b, d); // 21


        if(C != Z || D != Z)
            return true;
    }

    // simple case

    if (ab[0] == ab[1])
       return false;

    orientation_t cd[2];
    cd[0] = orientation(c, d, a, z);
    cd[1] = orientation(c, d, b, z);


    return ab[0] != ab[1];
}


