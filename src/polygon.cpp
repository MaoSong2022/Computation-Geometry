#include "polygon.hpp"

#include <limits>

namespace Geometry {
Vec3d Polygon::support(const Vec3d& d) const {
  int index = -1;
  double max_value = std::numeric_limits<double>::lowest();
  for (int i = 0; i < vertices_.size(); ++i) {
    double dot_product = (vertices_[i] - center_).dot_product(d);
    if (dot_product > max_value) {
      max_value = dot_product;
      index = i;
    }
  }
  return vertices_[index];
};

bool Polygon::contains(const Vec3d& point) const {
  int num_intersections = 0;
  int num_vertices = vertices().size();
  for (int i = 0; i < num_vertices; ++i) {
    // get the edge
    Vec3d p1 = vertices()[i];
    Vec3d p2 = vertices()[(i + 1) % num_vertices];
    // check if the edge intersects with the horizontal ray
    if ((p1.y > point.y) != (p2.y > point.y) &&
        (point.x < (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x)) {
      ++num_intersections;
    }
  }
  return num_intersections % 2 == 1;
}
}  // namespace Geometry
