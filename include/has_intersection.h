/// author: Viacheslav

#pragma once

#include <segment.h>
#include <point.h>
#include <my_orientation.h>


#include<iostream>
using namespace std;


template<class T>
bool has_intersection(Segment3D<T> const & sa, Segment3D<T> const & sb)
{

    Point3D<T> a(sa[0]), b(sa[1]), c(sb[0]), d(sb[1]), z(0.0,0.0,0.0);

    orientation_t ab[2];
    ab[0] = orientation(a, b, c, z);
    ab[1] = orientation(a, b, d, z);


    cout<<ab[0] << " " <<ab[1]<<endl;


    if (ab[0] == ab[1] && ab[0] == CG_COLLINEAR)
    {
        cout<<"BIG CYCLE case!!"<<endl;
        // segments are on one big circle
        Point3d n1(a.y*b.z - a.z*b.y,
                 -a.x*b.z + a.z*b.x,
                   a.x*b.y - a.y*b.x); // ON1
        //  i  j  k
        // ax ay az
        // bx by bz

        orientation_t C, D;
        C = orientation(n1, a, c, b); // 21
        D = orientation(n1, a, d, b); // 21

        if(C >= CG_COLLINEAR || D >= CG_COLLINEAR)
            return true;

        return false;
    }

    orientation_t t1 = orientation (a, b, c, d);  // 0 1 2 - 3
    orientation_t t2 = orientation (a, b, c, z);                  // 0 1 2 - O.O.O

    orientation_t t3 = orientation (b, c, d, a);   // 0 1 3 - 2
    orientation_t t4 = orientation (b, c, d, z);

    orientation_t t5 = orientation (a, b, d, c);   // 0 2 3 - 1
    orientation_t t6 = orientation (a, b, d, z);

    orientation_t t7 = orientation (a, d, c, b);
    orientation_t t8 = orientation (a, d, c, z);


    if(((t1 == t2) && (t3 == t4) && (t5 == t6) && (t7 == t8)))
    {
        // in different hemispheres
        cout<<"DIFFERENT hEMISPHERE case"<<endl;
        return false;
    }

    // in same hemispheres

    // simple case

    cout<<"SIMPLE case"<<endl;

    if (ab[0] == ab[1])
       return false;

    cout<<"SIMPLE case part 2"<<endl;

    orientation_t cd[2];
    cd[0] = orientation(c, d, a, z);
    cd[1] = orientation(c, d, b, z);


    return cd[0] != cd[1];
}


