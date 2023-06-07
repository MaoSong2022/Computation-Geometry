#include <iostream>
#include <gtest/gtest.h>

// #include "include/GJK.hpp"
// #include "include/polygon.hpp"
// #include "include/shape.hpp"

// using namespace GJK;

// int main(int argc, char *argv[])
// {
//   std::vector<GJK::Point> vertices1{GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0),
//                                     GJK::Point(9.0, 9.0)};
//   std::vector<GJK::Point> vertices2{GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0),
//                                     GJK::Point(9.0, 9.0)};
//   std::vector<GJK::Point> vertices3{GJK::Point(2.0, 4.0), GJK::Point(6.0, 5.0),
//                                     GJK::Point(11.0, 4.0),
//                                     GJK::Point(8.0, -1.0)};
//   GJK::Shape *triangle1 = new GJK::Polygon(vertices1);
//   GJK::Shape *triangle2 = new GJK::Polygon(vertices2);
//   GJK::Shape *polygon3 = new GJK::Polygon(vertices3);
//   auto status = GJK::algorithm(triangle1, triangle2);
//   std::cout << "two polygons collides, output is " << status << std::endl;
//   status = GJK::algorithm(triangle1, polygon3);
//   std::cout << "two polygons does not collide, output is " << status
//             << std::endl;
//   return 0;
// }

