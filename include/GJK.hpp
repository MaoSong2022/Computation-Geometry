
#include "shape.hpp"

namespace GJK {
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool algorithm(Shape *a, Shape *b);

Point support(Shape *a, Shape *b, const Point &d);

Point triple_product(const Point &a, const Point &b, const Point c);

bool contains_origin(std::vector<Point> &simplex, Point &d);
}  // namespace GJK