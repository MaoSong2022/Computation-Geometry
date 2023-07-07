#pragma once

#include "shape.hpp"

namespace Geometry {
class Polygon : public Shape {
 public:
  Polygon() = default;
  Polygon(const std::vector<Point>& vertices) : Shape(vertices, Point()) {
    for (const auto& vertex : vertices_) {
      center_ += vertex;
    }
    center_ /= (1.0 * vertices.size());
  }
  ~Polygon() {}

  Point support(const Point& d) const override;
};
}  // namespace Geometry