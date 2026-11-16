#include "sensor_buffer.hpp"
#include "status.hpp"

Status add_reading(SensorBuffer &buffer, float temperature) {
  if (buffer.counter >= buffer.CAPACITY) {
    return Status::STATUS_BUFFER_FULL;
  }

  buffer.temperature_buffer[buffer.counter] = temperature;
  buffer.counter++;

  return Status::STATUS_OK;
}

Status get_reading(const SensorBuffer &buffer, std::size_t index,
                   float &temperature) {
  if ((index < buffer.counter) && (index < buffer.CAPACITY)) {
    temperature = buffer.temperature_buffer[index];
    return Status::STATUS_OK;
  }
  return Status::STATUS_INVALID_ARGUMENT;
}