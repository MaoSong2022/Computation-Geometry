
#include "circle.hpp"

namespace Geometry {
Point Circle::support(const Point& d) const { return center_ + d.normalize(); };
}  // namespace Geometry
