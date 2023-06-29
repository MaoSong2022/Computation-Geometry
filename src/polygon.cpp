#include "polygon.hpp"

#include <limits>

namespace GJK {
Point Polygon::support(const Point& d) const {
  int index = 0;
  double max_value = std::numeric_limits<double>::lowest();
  for (int i = 0; i < vertices_.size(); ++i) {
    double dot_product = (vertices_[i] - center_).dot_product(d);
    if (dot_product > max_value) {
      max_value = dot_product;
      i = index;
    }
  }
  return vertices_[index];
};
}  // namespace GJK
