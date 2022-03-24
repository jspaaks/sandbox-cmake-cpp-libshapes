#include "gtest/gtest.h"
#include "circle.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


TEST(CircleTests, calcAreaWithPositiveRadius) {
    shapes::Circle circle(2.0);
    double actual_area = circle.calcArea();
    double expected_area = 12.56;
    double acceptable_difference = 0.01;
    ASSERT_NEAR(actual_area, expected_area, acceptable_difference);
}

TEST(CircleTests, accessRadiusMember) {
    shapes::Circle circle(1.23);
    double actual_radius = circle.radius;
    double expected_radius = 1.23;
    ASSERT_EQ(actual_radius, expected_radius);
}
