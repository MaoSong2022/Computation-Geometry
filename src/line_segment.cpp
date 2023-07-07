#include "line_segment.hpp"

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
}  // namespace Geometry