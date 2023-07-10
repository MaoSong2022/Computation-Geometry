#include "line_segment.hpp"

#include <algorithm>

namespace Geometry {
Point LineSegment::support(const Point& d) const {
  double dot_product1 = (endpoint1_ - center_).dot_product(d);
  double dot_product2 = (endpoint2_ - center_).dot_product(d);
  if (dot_product1 > dot_product2) {
    return endpoint1_;
  } else {
    return endpoint2_;
  }
};

bool LineSegment::contains(const Point& point) const {
  if ((point - endpoint1_).cross_product(endpoint2_ - endpoint1_) == kOrigin &&
      std::min(endpoint1_.x, endpoint2_.x) <= point.x &&
      point.x <= std::max(endpoint1_.x, endpoint2_.x) &&
      std::min(endpoint1_.y, endpoint2_.y) <= point.y &&
      point.y <= std::max(endpoint1_.y, endpoint2_.y) &&
      std::min(endpoint1_.z, endpoint2_.z) <= point.z &&
      point.z <= std::max(endpoint1_.z, endpoint2_.z)) {
    return true;
  }
  return false;
}

double LineSegment::distance_to(const Point& point) const {
  const double kEps = 1e-6;
  Point perpendicular;
  // check if the line segment is parallel to axis
  if (endpoint1_.x == endpoint2_.x) {
    perpendicular = Point(endpoint1_.x, point.y);
  } else if (endpoint1_.y == endpoint2_.y) {
    perpendicular = Point(point.x, endpoint1_.y);
  } else {
    // compute the perpendicular point to the line defined by two end points
    Point direction = (endpoint2_ - endpoint1_).normalize();
    Point projection = point - endpoint1_;
    perpendicular = endpoint1_ + projection.dot_product(direction) * direction;
  }
  // check if the perpendicular point is on the line segment
  if (contains(perpendicular)) {
    return point.distance_to(perpendicular);
  }
  return std::min(point.distance_to(endpoint1_), point.distance_to(endpoint2_));
}

}  // namespace Geometry