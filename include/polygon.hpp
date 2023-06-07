#pragma once

#include "shape.hpp"

namespace GJK {
class Polygon {
 private:
  std::vector<Point> vertices_;
  Point center_;

 public:
  Polygon() = default;
  Polygon(const std::vector<Point>& vertices)
      : vertices_(vertices), center_(Point()) {
    for (const auto& vertex : vertices_) {
      center_ += vertex;
    }
    center_ /= (1.0 * vertices.size());
  }
  ~Polygon(){}

  Point center() const { return vertices_[0]; }

  Point support(const Point& d) const;
};
}  // namespace GJK