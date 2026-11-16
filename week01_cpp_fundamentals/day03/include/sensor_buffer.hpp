#ifndef SENSOR_BUFFER_HPP
#define SENSOR_BUFFER_HPP

#include <array>
#include <cstddef>
#include <cstdint>

#include "status.hpp"

struct SensorBuffer {

  static constexpr std::size_t CAPACITY = 5;

  std::array<float, CAPACITY> temperature_buffer;
  std::uint16_t counter = 0;
};

Status add_reading(SensorBuffer &buffer, float temperature);
Status get_reading(const SensorBuffer &buffer, std::size_t index,
                   float &temperature);

#endif