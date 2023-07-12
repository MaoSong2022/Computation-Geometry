#pragma once

#include "shape.hpp"

namespace Geometry {
class Polygon : public Shape {
 public:
  Polygon() = default;
  Polygon(const std::vector<Vec3d>& vertices) : Shape(vertices, Vec3d()) {
    for (const auto& vertex : vertices_) {
      center_ += vertex;
    }
    center_ /= (1.0 * vertices.size());
  }
  ~Polygon() {}

  Vec3d support(const Vec3d& d) const override;
};
}  // namespace Geometry