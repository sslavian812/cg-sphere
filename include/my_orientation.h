/// author: Viacheslav

#pragma once

#include "point.h"
#include <boost/numeric/interval.hpp>
#include <gmpxx.h>

#include <boost/optional.hpp>

using boost::numeric::interval;

typedef boost::numeric::interval_lib::unprotect<boost::numeric::interval<double> >::type intervalD;
typedef Point3D<intervalD> Point3DI;
typedef Point3D<mpq_class> Point3DM;

enum orientation_t
{
  CG_RIGHT = -1,
  CG_COLLINEAR = 0,
  CG_LEFT = 1
};

inline bool opposite(orientation_t a, orientation_t b)
{
  if (a == CG_COLLINEAR || b == CG_COLLINEAR)
     return false;

  return a == -b;
}



struct orientation_floating_point
{
  boost::optional<orientation_t> operator() (Point3d const & a, Point3d const & b, Point3d const &  c, int multiplyer = 18) const
  {
     double p1 =  a.x*(b.y*c.z - b.z*c.y);
     double p2 =  a.y*(b.x*c.z - b.z*c.x);
     double p3 =  a.z*(b.x*c.y - b.y*c.x);
     double res = p1 - p2 + p3;
     double eps = (fabs(p1) + fabs(p2) + fabs(p3)) * multiplyer * std::numeric_limits<double>::epsilon(); // множитель аналогичными выкладками как в викиконспектах

     if (res > eps)
        return CG_LEFT;

     if (res < -eps)
        return CG_RIGHT;

     return boost::none;
  }
};

struct orientation_interval
{
  boost::optional<orientation_t> operator() (Point3DI const & a, Point3DI const & b, Point3DI const & c) const
  {
     //boost::numeric::interval<double>::traits_type::rounding _;

     intervalD p1 =  a.x*(b.y*c.z - b.z*c.y);
     intervalD p2 =  a.y*(b.x*c.z - b.z*c.x);
     intervalD p3 =  a.z*(b.x*c.y - b.y*c.x);

     intervalD res = p1 - p2 + p3;

     if (res.lower() > 0)
        return CG_LEFT;

     if (res.upper() < 0)
        return CG_RIGHT;

     if (res.upper() == res.lower())
        return CG_COLLINEAR;

     return boost::none;
  }
};


struct orientation_rational
{
  boost::optional<orientation_t> operator() (Point3DM const & a, Point3DM const & b, Point3DM const & c) const
  {
     mpq_class p1 =  a.x*(b.y*c.z - b.z*c.y);
     mpq_class p2 =  a.y*(b.x*c.z - b.z*c.x);
     mpq_class p3 =  a.z*(b.x*c.y - b.y*c.z);

     mpq_class res = p1 - p2 + p3;

     int cres = cmp(res, 0);

     if (cres > 0)
        return CG_LEFT;

     if (cres < 0)
        return CG_RIGHT;

     return CG_COLLINEAR;
  };
};

/*

// сделать ориентацию от четырех точек,
// чтобы в аргументах функции не вычетать даблы
// отнимать уже в этом куске кода
inline orientation_t orientation(Point3d const & a, Point3d const & b, Point3d const & c,int multiplyer = 18)
{
  if (boost::optional<orientation_t> v = orientation_floating_point()(a, b, c, multiplyer))
     return *v;

    Point3D<intervalD>p1((intervalD)a.x, (intervalD)a.y, (intervalD)a.z);
    Point3D<intervalD>p2((intervalD)b.x, (intervalD)b.y, (intervalD)b.z);
    Point3D<intervalD>p3((intervalD)c.x, (intervalD)c.y, (intervalD)c.z);

  if (boost::optional<orientation_t> v = orientation_interval()(p1, p2, p3))
     return *v;

  return *(orientation_rational()(a, b, c));
}

*/


// 4-opints oriantation here!
inline orientation_t orientation(Point3d const & a, Point3d const & b, Point3d const & c, Point3d const & d)
{
    if (boost::optional<orientation_t> v = orientation_floating_point()(a-d, b-d, c-d, 23)) // ??
        return *v;

    Point3DI p1i((intervalD)a.x-(intervalD)d.x, (intervalD)a.y-(intervalD)d.y, (intervalD)a.z-(intervalD)d.z);
    Point3DI p2i((intervalD)b.x-(intervalD)d.x, (intervalD)b.y-(intervalD)d.y, (intervalD)b.z-(intervalD)d.z);
    Point3DI p3i((intervalD)c.x-(intervalD)d.x, (intervalD)c.y-(intervalD)d.y, (intervalD)c.z-(intervalD)d.z);

    if (boost::optional<orientation_t> v = orientation_interval()(p1i, p2i, p3i))
        return *v;

    Point3DM p1m(mpq_class(a.x)-mpq_class(d.x), mpq_class(a.y)-mpq_class(d.y), mpq_class(a.z)-mpq_class(d.z));
    Point3DM p2m(mpq_class(b.x)-mpq_class(d.x), mpq_class(b.y)-mpq_class(d.y), mpq_class(b.z)-mpq_class(d.z));
    Point3DM p3m(mpq_class(c.x)-mpq_class(d.x), mpq_class(c.y)-mpq_class(d.y), mpq_class(c.z)-mpq_class(d.z));

    return *(orientation_rational()(p1m, p2m, p3m));
}


