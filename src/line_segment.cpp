#include "line_segment.hpp"

#include <algorithm>

namespace Geometry {
Vec3d LineSegment::support(const Vec3d& d) const {
  double dot_product1 = (endpoint1_ - center_).dot_product(d);
  double dot_product2 = (endpoint2_ - center_).dot_product(d);
  if (dot_product1 > dot_product2) {
    return endpoint1_;
  } else {
    return endpoint2_;
  }
};

bool LineSegment::contains(const Vec3d& point) const {
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

double LineSegment::distance_to(const Vec3d& point) const {
  const double kEps = 1e-6;
  Vec3d perpendicular;
  // check if the line segment is parallel to axis
  if (endpoint1_.x == endpoint2_.x) {
    perpendicular = Vec3d(endpoint1_.x, point.y);
  } else if (endpoint1_.y == endpoint2_.y) {
    perpendicular = Vec3d(point.x, endpoint1_.y);
  } else {
    // compute the perpendicular point to the line defined by two end points
    Vec3d direction = (endpoint2_ - endpoint1_).normalize();
    Vec3d projection = point - endpoint1_;
    perpendicular = endpoint1_ + projection.dot_product(direction) * direction;
  }
  // check if the perpendicular point is on the line segment
  if (contains(perpendicular)) {
    return point.distance_to(perpendicular);
  }
  return std::min(point.distance_to(endpoint1_), point.distance_to(endpoint2_));
}

bool LineSegment::intersects(const LineSegment& other) const {
  double this_left_bound = std::min(endpoint1_.x, endpoint2_.x);
  double this_right_bound = std::max(endpoint1_.x, endpoint2_.x);
  double this_lower_bound = std::min(endpoint1_.y, endpoint2_.y);
  double this_upper_bound = std::max(endpoint1_.y, endpoint2_.y);
}

}  // namespace Geometry