/// author: Viacheslav

#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "point.h"
#include <boost/numeric/interval.hpp>
#include <gmpxx.h>

#include <boost/optional.hpp>

using boost::numeric::interval;

typedef boost::numeric::interval_lib::unprotect<boost::numeric::interval<double> >::type intervalD;

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
  boost::optional<orientation_t> operator() (Point3d const & a, Point3d const & b, Point3d const & c) const
  {
     //boost::numeric::interval<double>::traits_type::rounding _;

     intervalD p1 =  intervalD(a.x)*(intervalD(b.y)*intervalD(c.z) - intervalD(b.z)*intervalD(c.y));
     intervalD p2 =  intervalD(a.y)*(intervalD(b.x)*intervalD(c.z) - intervalD(b.z)*intervalD(c.x));
     intervalD p3 =  intervalD(intervalD(a.z)*(intervalD(b.x)*intervalD(c.y) - intervalD(b.y)*intervalD(c.x)));

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
  boost::optional<orientation_t> operator() (Point3d const & a, Point3d const & b, Point3d const & c) const
  {
     mpq_class p1 =  mpq_class(a.x)*(mpq_class(b.y)*mpq_class(c.z) - mpq_class(b.z)*mpq_class(c.y));
     mpq_class p2 =  mpq_class(a.y)*(mpq_class(b.x)*mpq_class(c.z) - mpq_class(b.z)*mpq_class(c.x));
     mpq_class p3 =  mpq_class(a.z)*(mpq_class(b.x)*mpq_class(c.y) - mpq_class(b.y)*mpq_class(c.x));

     mpq_class res = p1 - p2 + p3;

     int cres = cmp(res, 0);

     if (cres > 0)
        return CG_LEFT;

     if (cres < 0)
        return CG_RIGHT;

     return CG_COLLINEAR;
  }
};


inline orientation_t orientation(Point3d const & a, Point3d const & b, Point3d const & c,int multiplyer = 18)
{
  if (boost::optional<orientation_t> v = orientation_floating_point()(a, b, c, multiplyer))
     return *v;

  if (boost::optional<orientation_t> v = orientation_interval()(a, b, c))
     return *v;

  return *(orientation_rational()(a, b, c));
}

#endif // ORIENTATION_H