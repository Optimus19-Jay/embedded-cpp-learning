#include <cstdint>
#include <gtest/gtest.h>

#include "sensor_data.hpp"

TEST(SensorValueUpdateTest, NullPointer) {

  Status status = update_sensor_value(nullptr);

  ASSERT_EQ(status, Status::STATUS_NULL_POINTER);
}

TEST(SensorValueUpdateTest, ValidPointer) {
  std::uint32_t valid_value = 100;

  Status status = update_sensor_value(&valid_value);

  EXPECT_EQ(status, Status::STATUS_OK);
  EXPECT_EQ(valid_value, 250);
}