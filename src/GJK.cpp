#include "GJK.hpp"

#include <algorithm>
#include <vector>

#include "line_segment.hpp"

namespace Geometry {
bool GJK_algorithm(const Shape *a, const Shape *b) {
  Vec3d d = (a->center() - b->center()).normalize();
  std::vector<Vec3d> simplex;
  simplex.push_back(support(a, b, d));
  d = kOrigin - simplex.front();
  while (true) {
    Vec3d A = support(a, b, d);
    if (A.dot_product(d) < 0) {
      return false;
    }
    simplex.push_back(A);
    if (contains_origin(simplex, d)) {
      return true;
    }
  }
  return true;
};

Vec3d support(const Shape *a, const Shape *b, const Vec3d &d) {
  return a->support(d) - b->support(-d);
};

Vec3d triple_product(const Vec3d &a, const Vec3d &b, const Vec3d &c) {
  return a.cross_product(b).cross_product(c);
};

bool is_same_direction(const Vec3d &d1, const Vec3d &d2) {
  return d1.dot_product(d2) > 0;
}

bool line_case(std::vector<Vec3d> &simplex, Vec3d &d) {
  const Vec3d &b = simplex[0];
  const Vec3d &a = simplex[1];
  if (LineSegment(a, b).contains(kOrigin)) {
    return true;
  }
  if (is_same_direction(b - a, -a)) {
    d = triple_product(b - a, -a, b - a);
  } else {
    simplex = std::vector<Vec3d>{a};
    d = -a;
  }
  return false;
}

bool contains_origin(std::vector<Vec3d> &simplex, Vec3d &d) {
  if (simplex.size() == 2) {
    return line_case(simplex, d);
  } else {
    // triangle case
    const Vec3d c = simplex[0], b = simplex[1], a = simplex[2];
    const Vec3d ab_perpendicular = triple_product(c - a, b - a, b - a);
    const Vec3d ac_perpendicular = triple_product(b - a, c - a, c - a);
    if (ab_perpendicular.dot_product(kOrigin - a) > 0.0) {
      // the origin is in the region AB
      simplex = std::vector<Vec3d>{b, a};
      d = ab_perpendicular;
      return false;
    } else if (ac_perpendicular.dot_product(kOrigin - a)) {
      // the origin is in the region AC
      simplex = std::vector<Vec3d>{c, a};
      d = ac_perpendicular;
      return false;
    }
    return true;
  }
};
}  // namespace Geometry