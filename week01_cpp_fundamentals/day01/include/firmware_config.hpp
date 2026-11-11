#ifndef FIRMWARE_CONFIG_HPP
#define FIRMWARE_CONFIG_HPP

#include "status.hpp"
#include <cstdint>

struct FirmwareConfig {
  std::uint32_t controller_id;
  float firmware_version;
  std::uint32_t operating_frequency;
  bool communication_enabled;
  bool diagnostics_enabled;
};

Status validate_firmware_config(const FirmwareConfig &config);

#endif