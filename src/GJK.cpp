#include <vector>

#include "GJK.hpp"

namespace GJK {
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool GJK(const Shape *a, const Shape *b) {
  const Point origin(0.0, 0.0, 0.0);
  Point d = (a->center() - b->center()).normalize();
  std::vector<Point> simplex;
  simplex.push_back(support(*a, *b, d));
  d = origin - simplex.front();
  while (true) {    
    Point A = support(*a, *b, d);
    if (A.dot(d) < 0) {  // use epsilon
      return false; 
    }
     if (contains_origin(simplex, d)) {
      return true;
    }
  }
  return true;
};

Point support(const Shape &a, const Shape &b, const Point &d) {
  return a.support(d) - b.support(Point(0, 0, 0) - d);
};

Point triple_product(const Point &a, const Point &b, const Point c) {
  return a.cross_product(b).cross_product(c);
};

bool contains_origin(std::vector<Point> &simplex, Point &d) {
  const Point o(0.0, 0.0, 0.0);
  if (simplex.size() == 2) {
    // line case
    const Point &b = simplex[0], &a = simplex[1];
    const Point ab_perpencular = triple_product(b - a, a - o, b - a);
    d = ab_perpencular;
    return false;
  } else {
    // triangle case
    const Point c = simplex[0], b = simplex[1], a = simplex[2];
    const Point ab_perpencular = triple_product(c - a, b - a, b - a);
    const Point ac_perpencular = triple_product(b - a, c - a, c - a);
    if (ab_perpencular.dot(o - a) > 0.0){
      // the origin is in the region AB
      simplex = std::vector<Point>{b, a};
      d = ab_perpencular;
      return false;
    } else if (ac_perpencular.dot(o - a)) {
      // the origin is in the region AC
      simplex = std::vector<Point>{c, a};
      d = ac_perpencular;
      return false;
    }
    return true;
  }
};
}  // namespace GJK