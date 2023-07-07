
#include <gtest/gtest.h>

#include <vector>

#include "GJK.hpp"
#include "point.hpp"
#include "polygon.hpp"

class GJKTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    std::vector<Geometry::Point> vertices1{Geometry::Point(4.0, 11.0),
                                           Geometry::Point(5.0, 5.0),
                                           Geometry::Point(9.0, 9.0)};
    std::vector<Geometry::Point> vertices2{
        Geometry::Point(2.0, 4.0), Geometry::Point(6.0, 5.0),
        Geometry::Point(11.0, 4.0), Geometry::Point(8.0, -1.0)};
    triangle1 = new Geometry::Polygon(vertices1);
    triangle2 = new Geometry::Polygon(vertices2);
  }

  void TearDown() override {
    delete triangle1;
    delete triangle2;
  }

  Geometry::Shape *triangle1;
  Geometry::Shape *triangle2;
  const double kEPS = 1e-3;
};

TEST_F(GJKTestSuite, TripleProduct) {
  Geometry::Point result = Geometry::triple_product(
      triangle1->vertices()[1] - triangle1->vertices()[0],
      triangle1->vertices()[0] - Geometry::Point(0, 0, 0),
      triangle1->vertices()[1] - triangle1->vertices()[0]);
  ASSERT_NEAR(result.x, 210, kEPS);
  ASSERT_NEAR(result.y, 35, kEPS);
  ASSERT_NEAR(result.z, 0, kEPS);
}

TEST_F(GJKTestSuite, CollisionFree) {
  ASSERT_FALSE(Geometry::GJK_algorithm(triangle1, triangle2));
}
