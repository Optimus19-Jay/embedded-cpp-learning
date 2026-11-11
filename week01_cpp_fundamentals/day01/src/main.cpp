#include <iostream>

#include "firmware_config.hpp"

int main() {

  FirmwareConfig config;
  config.controller_id = 1;
  config.firmware_version = 2.0f;
  config.operating_frequency = 50000;
  config.communication_enabled = true;
  config.diagnostics_enabled = false;

  Status result = validate_firmware_config(config);

  if (result != Status::STATUS_OK) {
    std::cerr << "Firmware configuration is invalid." << std::endl;
    return 1;
  }

  std::cout << "Firmware config is valid." << std::endl;

  return 0;
}