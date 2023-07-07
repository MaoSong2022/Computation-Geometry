#include <gtest/gtest.h>

#include "point.hpp"

class PointTestSuite : public ::testing::Test {
 protected:
  void SetUp() override {
    point1 = Geometry::Point(1.0, 2.0, 3.0);
    point2 = Geometry::Point(3.0, 2.0, 1.0);
    scalar = 2.0;
  }

  void TearDown() override {}

  Geometry::Point point1;
  Geometry::Point point2;
  double scalar;
  const double kEPS = 1e-3;
};

TEST_F(PointTestSuite, Minus) {
  Geometry::Point point_difference = point1 - point2;
  ASSERT_NEAR(point_difference.x, -2.0, kEPS);
  ASSERT_NEAR(point_difference.y, 0.0, kEPS);
  ASSERT_NEAR(point_difference.z, 2.0, kEPS);
}

TEST_F(PointTestSuite, Add) {
  Geometry::Point point_sum = point1 + point2;
  ASSERT_NEAR(point_sum.x, 4.0, kEPS);
  ASSERT_NEAR(point_sum.y, 4.0, kEPS);
  ASSERT_NEAR(point_sum.z, 4.0, kEPS);
}

TEST_F(PointTestSuite, SelfAdd) {
  point1 += point2;
  ASSERT_NEAR(point1.x, 4.0, kEPS);
  ASSERT_NEAR(point1.y, 4.0, kEPS);
  ASSERT_NEAR(point1.z, 4.0, kEPS);
}

TEST_F(PointTestSuite, Divide) {
  Geometry::Point point_scaled = point1 / scalar;
  ASSERT_NEAR(point_scaled.x, 0.5, kEPS);
  ASSERT_NEAR(point_scaled.y, 1.0, kEPS);
  ASSERT_NEAR(point_scaled.z, 1.5, kEPS);
}

TEST_F(PointTestSuite, Negative) {
  Geometry::Point point_negative = -point1;
  ASSERT_NEAR(point_negative.x, -1.0, kEPS);
  ASSERT_NEAR(point_negative.y, -2.0, kEPS);
  ASSERT_NEAR(point_negative.z, -3.0, kEPS);
}

TEST_F(PointTestSuite, Normalize) {
  Geometry::Point point_negative = point1.normalize();
  ASSERT_NEAR(point_negative.x, 0.26726124, kEPS);
  ASSERT_NEAR(point_negative.y, 0.53452248, kEPS);
  ASSERT_NEAR(point_negative.z, 0.80178373, kEPS);
}

TEST_F(PointTestSuite, DotProduct) {
  double point_dot_product = point1.dot_product(point2);
  ASSERT_NEAR(point_dot_product, 10.0, kEPS);
}

TEST_F(PointTestSuite, CrossProduct) {
  Geometry::Point point_cross_product = point1.cross_product(point2);
  ASSERT_NEAR(point_cross_product.x, -4.0, kEPS);
  ASSERT_NEAR(point_cross_product.y, 8.0, kEPS);
  ASSERT_NEAR(point_cross_product.z, -4.0, kEPS);
}