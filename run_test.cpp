#include <iostream>

#include "include/GJK.hpp"
#include "include/polygon.hpp"

using namespace GJK;

int main(int argc, char *argv[])
{
  std::vector<GJK::Point> vertices1{GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0),
                                    GJK::Point(9.0, 9.0)};
  std::vector<GJK::Point> vertices2{GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0),
                                    GJK::Point(9.0, 9.0)};
  GJK::Polygon *triangle1 = new GJK::Polygon(vertices1);
  GJK::Polygon *triangle2 = new GJK::Polygon(vertices2);
  auto status = GJK::algorithm(triangle1, triangle2);
  std::cout << status << std::endl;
  std::cout << "hello" << std::endl;
  return 0;
}
