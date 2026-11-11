#include "firmware_config.hpp"

Status validate_firmware_config(const FirmwareConfig &config) {
  if (config.controller_id == 0) {
    return Status::STATUS_INVALID_ARGUMENT;
  }

  if (config.firmware_version < 1.0f) {
    return Status::STATUS_INVALID_ARGUMENT;
  }

  if (config.operating_frequency < 1000 ||
      config.operating_frequency > 100000) {
    return Status::STATUS_INVALID_ARGUMENT;
  }

  if (!config.communication_enabled) {
    return Status::STATUS_INVALID_ARGUMENT;
  }

  return Status::STATUS_OK;
}