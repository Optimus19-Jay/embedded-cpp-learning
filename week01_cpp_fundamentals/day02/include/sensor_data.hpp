#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

#include "status.hpp"
#include <cstdint>

Status update_sensor_value(std::uint32_t *sensor_value);

#endif