#include <iostream>

#include "GJK.hpp"
#include "polygon.hpp"

int main(int argc, char const *argv[]) {
  std::vector<GJK::Point> vertices1{GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0),
                                    GJK::Point(9.0, 9.0)};
  std::vector<GJK::Point> vertices2{GJK::Point(7.0, 9.0), GJK::Point(13.0, 11.0),
                                    GJK::Point(11.0, 6.0)};
  std::vector<GJK::Point> vertices3{GJK::Point(2.0, 4.0), GJK::Point(6.0, 5.0),
                                    GJK::Point(11.0, 4.0),
                                    GJK::Point(8.0, -1.0)};
  GJK::Shape *triangle1 = new GJK::Polygon(vertices1);
  GJK::Shape *triangle2 = new GJK::Polygon(vertices2);
  GJK::Shape *polygon1 = new GJK::Polygon(vertices3);
  if (GJK::algorithm(triangle1, triangle2)) {
    std::cout << "In collision" << std::endl;
  } else {
    std::cout << "No collision" << std::endl;
  }
  if (GJK::algorithm(triangle1, polygon1)) {
    std::cout << "In collision" << std::endl;
  } else {
    std::cout << "No collision" << std::endl;
  }
  return 0;
}
