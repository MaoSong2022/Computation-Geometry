
#include "include/circle.hpp"

namespace GJK {
Point Circle::support(const Point& d) const { return center_ + d.normalize(); };
}  // namespace GJK
