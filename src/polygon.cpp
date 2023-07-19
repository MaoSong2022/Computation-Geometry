#include "polygon.hpp"

#include <algorithm>
#include <limits>
#include <set>
#include <stdexcept>
#include <vector>

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

bool Polygon::operator==(const Polygon& other) const {
  if (vertices().size() != other.vertices().size()) {
    return false;
  }
  return std::set<Vec3d>(vertices().begin(), vertices().end()) ==
         std::set<Vec3d>(other.vertices().begin(), other.vertices().end());
}

bool Polygon::operator!=(const Polygon& other) const {
  return !(*this == other);
}

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

bool Polygon::contains(const LineSegment& line_segment) const {
  return contains(line_segment.endpoint1()) &&
         contains(line_segment.endpoint2());
}

Polygon Polygon::from_vertices(std::vector<Vec3d>& points) {
  if (points.size() < 3) {
    throw std::invalid_argument("Requiring at least 3 points!");
  }

  // find the most left-lower point
  int index_lowest = 0;
  for (int i = 1; i < points.size(); ++i) {
    if (points[i].x < points[index_lowest].x ||
        points[i].y < points[index_lowest].y) {
      index_lowest = i;
    }
  }
  // set start point
  swap(points[index_lowest], points[0]);
  Vec3d start = points[0];

  // sort points in anti-clock direction
  auto compare_angle = [&start](const Vec3d& a, const Vec3d& b) -> bool {
    double angle = (b - a).cross_product_2d(a - start);

    if (angle == 0) {
      return a.distance_to(start) < b.distance_to(start);
    }
    return angle > 0;
  };
  std::sort(points.begin() + 1, points.end(), compare_angle);

  //
  std::vector<Vec3d> vertices;
  vertices.push_back(points[0]);
  vertices.push_back(points[1]);

  int count = 2;
  while (count < points.size()) {
    const Vec3d& a = vertices[vertices.size() - 2];
    const Vec3d& b = vertices[vertices.size() - 1];
    const Vec3d& c = points[count];
    if ((c - b).cross_product_2d(b - a) > 0) {
      vertices.push_back(c);
      ++count;
    } else {
      vertices.pop_back();
      if (vertices.size() < 2) {
        vertices.push_back(c);
        ++count;
      }
    }
  }

  const Vec3d& a = vertices[vertices.size() - 2];
  const Vec3d& b = vertices[vertices.size() - 1];
  const Vec3d& c = vertices[0];
  if ((c - b).cross_product_2d(b - a) <= 0) {
    vertices.pop_back();
  }

  return Polygon(vertices);
}
}  // namespace Geometry
