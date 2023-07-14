#pragma once

#include "SAT.hpp"

#include <limits>
#include <vector>

#include "vec3d.hpp"

namespace Geometry {

bool SAT_algorithm(const Shape *a, const Shape *b) {
  int m = a->vertices().size(), n = b->vertices().size();
  std::vector<Vec3d> edges;
  for (int i = 0; i < m; ++i) {
    edges.push_back(a->vertices()[(i + 1) % m] - a->vertices()[i]);
  }
  for (int j = 0; j < n; ++j) {
    edges.push_back(b->vertices()[(j + 1) % m] - b->vertices()[j]);
  }
  // TODO: only for 2d case, how to extend to 3d?
  std::vector<Vec3d> axes;
  for (const auto &edge : edges) {
    axes.push_back(Vec3d(edge.y, -edge.x, edge.z).normalize());
  }

  for (const auto &axe : axes) {
    double min_projection_a = std::numeric_limits<double>::infinity();
    double max_projection_a = std::numeric_limits<double>::lowest();
    for (const auto &vertex : a->vertices()) {
      min_projection_a = std::min(min_projection_a, vertex.dot_product(axe));
      max_projection_a = std::max(max_projection_a, vertex.dot_product(axe));
    }

    double min_projection_b = std::numeric_limits<double>::infinity();
    double max_projection_b = std::numeric_limits<double>::lowest();
    for (const auto &vertex : b->vertices()) {
      min_projection_b = std::min(min_projection_b, vertex.dot_product(axe));
      max_projection_b = std::max(max_projection_b, vertex.dot_product(axe));
    }
    // invoke separate axis theorem to check collision
    if (min_projection_a > max_projection_b ||
        min_projection_b > max_projection_a) {
      return false;
    }
  }
  return true;
}
}  // namespace Geometry