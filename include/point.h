/// author: Viacheslav

#pragma once

#include<math.h>

#include <boost/numeric/interval.hpp>
#include <gmpxx.h>

using boost::numeric::interval;

typedef boost::numeric::interval_lib::unprotect<boost::numeric::interval<double> >::type intervalD;

template <class T> struct Point3D;

typedef Point3D<double> Point3d;
typedef Point3D<float>  Point3f;
typedef Point3D<int>  Point3i;


template <class T>
struct Point3D
{
  T x, y, z;

  Point3D(T x, T y, T z)
     : x(x)
     , y(y)
     , z(z)
  {}


  Point3D(Point3D<T> const & other)
     : x(other.x)
     , y(other.y)
     , z(other.z)
  {}

  Point3D()
     : x(0)
     , y(0)
     , z(0)
  {}

};

template<class T>
Point3D<T> getDecart(T c, T a, T r)
{
//    intervalD ic =  interval<double>(c);
//    intervalD ia =  interval<double>(a);
//    intervalD ir =  interval<double>(r);

//    intervalD ix(ir*interval:: sin(ic)*cos(ia));
//    intervalD iy;
//    intervalD iz;

//    intervalD res = p1 - p2 + p3;

//    if (res.lower() > 0)
//       return CG_LEFT;

//    if (res.upper() < 0)
//       return CG_RIGHT;


//    Point3DM p1m(mpq_class(a.x)-mpq_class(d.x), mpq_class(a.y)-mpq_class(d.y), mpq_class(a.z)-mpq_class(d.z));
//    Point3DM p2m(mpq_class(b.x)-mpq_class(d.x), mpq_class(b.y)-mpq_class(d.y), mpq_class(b.z)-mpq_class(d.z));
//    Point3DM p3m(mpq_class(c.x)-mpq_class(d.x), mpq_class(c.y)-mpq_class(d.y), mpq_class(c.z)-mpq_class(d.z));


    return Point3D<T>(r*sin(c)*cos(a),r*sin(c)*sin(a), r*cos(c));
}

template<class T>
Point3D<T> getPolar(Point3D<T> p)
{
    return Point3D<T>(sqrt(p.x*p.x+ p.y*p.y+ p.z*p.z), acos(p.z/sqrt(p.x*p.x+ p.y*p.y+ p.z*p.z)), atan2(p.y,p.x));
}


template <class T>
inline bool operator < (Point3D<T> const & a, Point3D<T> const & b)
{
 if (a.x == b.x)
     return (a.y == b.y) ? (a.z < b.z) : (a.y< b.y);
 else
    return a.x < b.x;
}

template <class T>
bool operator > (Point3D<T> const & a, Point3D<T> const & b)
{
 return b < a;
}

template <class T>
bool operator == (Point3D<T> const & a, Point3D<T> const & b)
{
 return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

template <class T>
bool operator <= (Point3D<T> const & a, Point3D<T> const & b)
{
 return !(a > b);
}

template <class T>
bool operator >= (Point3D<T> const & a, Point3D<T> const & b)
{
 return !(a < b);
}


template <class T>
bool operator != (Point3D<T> const & a, Point3D<T> const & b)
{
 return !(a == b);
}

template <class T>
Point3D<T>  operator-=(Point3D<T> & a, Point3D<T> const & b)
{
  a.x-=b.x;
  a.y-=b.y;
  a.z-=b.z;
  return a;
}

template <class T>
Point3D<T>  operator+=(Point3D<T> & a, Point3D<T> const & b)
{
  a.x+=b.x;
  a.y+=b.y;
  a.z+=b.z;
  return a;
}

template <class T>
Point3D<T>  operator+(Point3D<T> const & a, Point3D<T> const & b)
{
  Point3D<T>c = a;
  c+=b;
  return c;
}

template <class T>
Point3D<T>  operator-(Point3D<T> const & a, Point3D<T> const & b)
{
    Point3D<T>c = a;
    c-=b;
    return c;
}



// google styleguide:
// Type names should start with a capital letter and have a capital letter for each new word. No underscores.
// Variable names are all lowercase, with underscores between words.
