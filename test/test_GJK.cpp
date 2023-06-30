
#include <gtest/gtest.h>

#include <vector>

#include "GJK.hpp"
#include "point.hpp"
#include "polygon.hpp"

class GJKTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    std::vector<GJK::Point> vertices1{
        GJK::Point(4.0, 11.0), GJK::Point(5.0, 5.0), GJK::Point(9.0, 9.0)};
    std::vector<GJK::Point> vertices2{
        GJK::Point(2.0, 4.0), GJK::Point(6.0, 5.0), GJK::Point(11.0, 4.0),
        GJK::Point(8.0, -1.0)};
    triangle1 = new GJK::Polygon(vertices1);
    triangle2 = new GJK::Polygon(vertices2);
  }

  void TearDown() override {
    delete triangle1;
    delete triangle2;
  }

  GJK::Shape *triangle1;
  GJK::Shape *triangle2;
};

TEST_F(GJKTestSuite, CollisionFree) {
  ASSERT_FALSE(GJK::algorithm(triangle1, triangle2));
}

// TEST(GJK_Test, InCollision) {
//   std::vector<GJK::Point> vertices1{GJK::Point(4.0, 11.0),
//   GJK::Point(5.0, 5.0),
//                                     GJK::Point(9.0, 9.0)};
//   std::vector<GJK::Point> vertices2{GJK::Point(4.0, 11.0),
//   GJK::Point(5.0, 5.0),
//                                     GJK::Point(9.0, 9.0)};
//   GJK::Shape *triangle1 = new GJK::Polygon(vertices1);
//   GJK::Shape *triangle2 = new GJK::Polygon(vertices2);
//   ASSERT_TRUE(GJK::algorithm(triangle1, triangle2));
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}