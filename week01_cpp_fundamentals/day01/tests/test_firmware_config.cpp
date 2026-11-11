#include <gtest/gtest.h>

#include "firmware_config.hpp"

class FirmwareConfigTest : public ::testing::Test {
protected:
  FirmwareConfig config{};

  void SetUp() override {
    config.controller_id = 12345;
    config.firmware_version = 1.2f;
    config.operating_frequency = 50000;
    config.communication_enabled = true;
    config.diagnostics_enabled = true;
  }
};

TEST_F(FirmwareConfigTest, ValidConfiguration) {

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_OK);
}

TEST_F(FirmwareConfigTest, InvalidControllerID) {

  config.controller_id = 0;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
}

TEST_F(FirmwareConfigTest, InvalidFirmwareVersion) {

  config.firmware_version = 0.5f;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
}

TEST_F(FirmwareConfigTest, OperatingFrequencyBelowMinimum) {

  config.operating_frequency = 999;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
}

TEST_F(FirmwareConfigTest, OperatingFrequencyAboveMaximum) {

  config.operating_frequency = 100001;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
}

TEST_F(FirmwareConfigTest, MinimumOperatingFrequencyIsValid) {
  config.operating_frequency = 1000;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_OK);
}

TEST_F(FirmwareConfigTest, MaximumOperatingFrequencyIsValid) {
  config.operating_frequency = 100000;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_OK);
}

TEST_F(FirmwareConfigTest, CommunicationDisabled) {
  config.communication_enabled = false;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_INVALID_ARGUMENT);
}

TEST_F(FirmwareConfigTest, DiagnosticDisabled) {
  config.diagnostics_enabled = false;

  Status status = validate_firmware_config(config);

  ASSERT_EQ(status, Status::STATUS_OK);
}
