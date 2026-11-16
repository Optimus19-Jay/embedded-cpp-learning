#include <array>
#include <cstddef>
#include <gtest/gtest.h>

#include "sensor_buffer.hpp"

TEST(SensorBufferAddReadingTest, StartsWithEmptyBuffer) {
  SensorBuffer buffer;

  EXPECT_EQ(buffer.counter, 0u);
}

TEST(SensorBufferAddReadingTest, StoresFirstReadingAndIncrementsCounter) {
  SensorBuffer buffer;
  constexpr float temperature = 21.5f;

  const Status status = add_reading(buffer, temperature);

  EXPECT_EQ(status, Status::STATUS_OK);
  EXPECT_EQ(buffer.counter, 1u);
  EXPECT_FLOAT_EQ(buffer.temperature_buffer[0], temperature);
}

TEST(SensorBufferAddReadingTest, StoresReadingsInOrderUntilCapacity) {
  SensorBuffer buffer;
  const std::array<float, SensorBuffer::CAPACITY> temperatures = {
      21.5f, 22.5f, 23.5f, 24.5f, 25.5f};

  for (std::size_t i = 0; i < temperatures.size(); ++i) {
    const Status status = add_reading(buffer, temperatures[i]);

    EXPECT_EQ(status, Status::STATUS_OK);
    EXPECT_EQ(buffer.counter, i + 1u);
    EXPECT_FLOAT_EQ(buffer.temperature_buffer[i], temperatures[i]);
  }
}

TEST(SensorBufferAddReadingTest, RejectsExtraReadingsOnceBufferIsFull) {
  SensorBuffer buffer;
  const std::array<float, SensorBuffer::CAPACITY> temperatures = {
      21.5f, 22.5f, 23.5f, 24.5f, 25.5f};

  for (const float temperature : temperatures) {
    ASSERT_EQ(add_reading(buffer, temperature), Status::STATUS_OK);
  }

  constexpr float extra_temperature = 99.9f;
  const Status status = add_reading(buffer, extra_temperature);

  EXPECT_EQ(status, Status::STATUS_BUFFER_FULL);
  EXPECT_EQ(buffer.counter, SensorBuffer::CAPACITY);
  for (std::size_t i = 0; i < temperatures.size(); ++i) {
    EXPECT_FLOAT_EQ(buffer.temperature_buffer[i], temperatures[i]);
  }
}

TEST(SensorBufferGetReadingTest, ReadsTemperatureAtValidIndex) {
  SensorBuffer buffer;
  const std::array<float, SensorBuffer::CAPACITY> temperatures = {
      21.5f, 22.5f, 23.5f, 24.5f, 25.5f};

  for (const float temperature : temperatures) {
    ASSERT_EQ(add_reading(buffer, temperature), Status::STATUS_OK);
  }

  for (std::size_t i = 0; i < temperatures.size(); ++i) {
    float retrieved_temperature = 0.0f;
    const Status status = get_reading(buffer, i, retrieved_temperature);

    EXPECT_EQ(status, Status::STATUS_OK);
    EXPECT_FLOAT_EQ(retrieved_temperature, temperatures[i]);
  }
}

TEST(SensorBufferGetReadingTest, RejectsUnpopulatedIndex) {
  SensorBuffer buffer;
  const std::array<float, 3> temperatures = {21.5f, 22.5f, 23.5f};

  for (const float temperature : temperatures) {
    ASSERT_EQ(add_reading(buffer, temperature), Status::STATUS_OK);
  }

  constexpr std::size_t unpopulated_index = 4;
  float retrieved_temperature = 99.9f;
  const Status status =
      get_reading(buffer, unpopulated_index, retrieved_temperature);

  EXPECT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
  EXPECT_EQ(buffer.counter, 3u);
  EXPECT_FLOAT_EQ(retrieved_temperature, 99.9f);
}

TEST(SensorBufferGetReadingTest, RejectsOutOfCapacityIndex) {
  SensorBuffer buffer;
  const std::array<float, 3> temperatures = {21.5f, 22.5f, 23.5f};

  for (const float temperature : temperatures) {
    ASSERT_EQ(add_reading(buffer, temperature), Status::STATUS_OK);
  }

  constexpr std::size_t out_of_bounds_index = SensorBuffer::CAPACITY;
  float retrieved_temperature = 99.9f;
  const Status status =
      get_reading(buffer, out_of_bounds_index, retrieved_temperature);

  EXPECT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
  EXPECT_EQ(buffer.counter, 3u);
  EXPECT_FLOAT_EQ(retrieved_temperature, 99.9f);
}