#pragma once


#include <boost/array.hpp>
#include "point.h"

template <class T> struct Segment3D;
typedef Segment3D<float> Segment3f;
typedef Segment3D<double> Segment3d;

template <class T>
struct Segment3D
{
  Segment3D() {}

  Segment3D(Point3D<T> const & beg, Point3D<T> const & end)
     : pts_( {{beg, end}} ) {}

  Point3D<T> & operator [] (size_t id) { return pts_[id]; }
  Point3D<T> const & operator [] (size_t id) const { return pts_[id]; }

private:
  boost::array<Point3D<T>, 2 > pts_;
};

template <class T>
bool operator == (Segment3D<T> const & a, Segment3D<T> const & b)
{
  return (a[0] == b[0]) && (a[1] == b[1]); // has the segment direction?
}

template <class T>
bool operator != (Segment3D<T> const & a, Segment3D<T> const & b)
{
  return !(a == b);
}

/*template <class T>
Point3D<T> const & min(Segment3D<T> const & seg) { return std::min(seg[0], seg[1]); }

template <class T>
Point3D<T> const & max(Segment3D<T> const & seg) { return std::max(seg[0], seg[1]); }*/


