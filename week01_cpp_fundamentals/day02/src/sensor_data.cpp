#include "sensor_data.hpp"

Status update_sensor_value(std::uint32_t *sensor_value) {
  if (sensor_value == nullptr) {
    return Status::STATUS_NULL_POINTER;
  }

  constexpr std::uint32_t temperature_value = 250;

  *sensor_value = temperature_value;
  return Status::STATUS_OK;
}