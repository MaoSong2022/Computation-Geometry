#include "rectangle.hpp"

#include <limits>

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
double Rectangle::lower_bound() const {
  double lower_bound = std::numeric_limits<double>::infinity();
  for (const auto &vertex : vertices_) {
    lower_bound = std::min(lower_bound, vertex.y);
  }
  return lower_bound;
}
double Rectangle::upper_bound() const {
  double upper_bound = std::numeric_limits<double>::lowest();
  for (const auto &vertex : vertices_) {
    upper_bound = std::max(upper_bound, vertex.y);
  }
  return upper_bound;
}

bool Rectangle::intersects(const Rectangle &other) const {
  if (this->lower_bound() > other.upper_bound()) {
    return false;
  }
  if (this->upper_bound() < other.lower_bound()) {
    return false;
  }
  if (this->left_bound() > other.right_bound()) {
    return false;
  }
  if (this->right_bound() < other.left_bound()) {
    return false;
  }
  // TODO: complete this part
}

}  // namespace Geometry
