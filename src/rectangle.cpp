#include "rectangle.hpp"

#include <algorithm>
#include <limits>

#include "GJK.hpp"

namespace Geometry {

double Rectangle::left_bound() const {
  double left_bound = std::numeric_limits<double>::infinity();
  for (const auto &vertex : vertices_) {
    left_bound = std::min(left_bound, vertex.x);
  }
  return left_bound;
}

double Rectangle::right_bound() const {
  double right_bound = std::numeric_limits<double>::lowest();
  for (const auto &vertex : vertices_) {
    right_bound = std::max(right_bound, vertex.x);
  }
  return right_bound;
}

double Rectangle::front_bound() const {
  double left_bound = std::numeric_limits<double>::infinity();
  for (const auto &vertex : vertices_) {
    left_bound = std::min(left_bound, vertex.y);
  }
  return left_bound;
}

double Rectangle::back_bound() const {
  double right_bound = std::numeric_limits<double>::lowest();
  for (const auto &vertex : vertices_) {
    right_bound = std::max(right_bound, vertex.y);
  }
  return right_bound;
}

double Rectangle::lower_bound() const {
  double lower_bound = std::numeric_limits<double>::infinity();
  for (const auto &vertex : vertices_) {
    lower_bound = std::min(lower_bound, vertex.z);
  }
  return lower_bound;
}

double Rectangle::upper_bound() const {
  double upper_bound = std::numeric_limits<double>::lowest();
  for (const auto &vertex : vertices_) {
    upper_bound = std::max(upper_bound, vertex.z);
  }
  return upper_bound;
}

bool Rectangle::AABBIntersects(const Rectangle &other) const {
  // use AABB to filter collision-free case
  if (this->lower_bound() > other.upper_bound()) {
    return false;
  }
  if (this->upper_bound() < other.lower_bound()) {
    return false;
  }
  if (this->front_bound() > other.back_bound()) {
    return false;
  }
  if (this->back_bound() < other.front_bound()) {
    return false;
  }
  if (this->left_bound() > other.right_bound()) {
    return false;
  }
  if (this->right_bound() < other.left_bound()) {
    return false;
  }
  return true;
}

bool Rectangle::intersects(const Rectangle &other) const {
  // use GJK algorithm to check collision
  if (!AABBIntersects(other)) {
    return false;
  }
  return GJK_algorithm(this, &other);
}

Rectangle AABBFromDiagonalPoints(const Vec3d &point1, const Vec3d &point2) {
  std::vector<Vec3d> vertices = {point1,
                                 Vec3d(point1.x, point1.y, point2.z),
                                 Vec3d(point1.x, point2.y, point1.z),
                                 Vec3d(point2.x, point1.y, point1.z),
                                 Vec3d(point2.x, point2.y, point1.z),
                                 Vec3d(point2.x, point1.y, point2.z),
                                 Vec3d(point1.x, point2.y, point2.z),
                                 point2};
  return Rectangle(vertices);
}

bool Rectangle::contains(const Vec3d &point) const {
  return point.x >= left_bound() && point.x <= right_bound() &&
         point.y >= front_bound() && point.y <= back_bound() &&
         point.z >= lower_bound() && point.z <= upper_bound();
}

bool Rectangle::contains(const Rectangle &other) const {
  for (const auto &vertex : other.vertices()) {
    if (!contains(vertex)) {
      return false;
    }
  }
  return true;
}

bool Rectangle::contains(const Circle &other) const {
  if (!contains(other.center())) {
    return false;
  }
  int n = vertices().size();
  for (int i = 0; i < n; ++i) {
    double distance =
        other.center().distance_to_Line(vertices()[(i + 1) % n], vertices()[i]);
    if (distance < other.radius()) {
      return false;
    }
  }
  return true;
}

}  // namespace Geometry
