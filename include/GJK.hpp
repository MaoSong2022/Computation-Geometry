
#include "shape.hpp"

namespace GJK{
/*
 * @brief determine if two convex shapes intersect
 * @return true if two shapes intersect.
 */
bool GJK(const Shape *a, const Shape *b);

Point support(const Shape &a, const Shape &b, const Point &d);

Point triple_product(const Point &a, const Point &b, const Point c);

bool contains_origin(std::vector<Point> &simplex, Point &d);
}