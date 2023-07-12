
#include "circle.hpp"

namespace Geometry {
Vec3d Circle::support(const Vec3d& d) const { return center_ + d.normalize(); };
}  // namespace Geometry
