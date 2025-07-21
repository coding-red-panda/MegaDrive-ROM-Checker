#include "gtest/gtest.h"
#include "support/device_support.h"

TEST(DeviceSupportTestSuite, getDeviceSupport) {
    std::string raw_data = "J";
    support::DeviceSupport deviceSupport(raw_data);

    EXPECT_EQ(deviceSupport.supportsThreeButtonController(), true);
    EXPECT_EQ(deviceSupport.supportsSixButtonController(), false);
    EXPECT_EQ(deviceSupport.supportMasterSystemController(), false);
    EXPECT_EQ(deviceSupport.supportsAnalogJoystick(), false);
    EXPECT_EQ(deviceSupport.supportsMultitap(), false);
    EXPECT_EQ(deviceSupport.supportsLightGun(), false);
    EXPECT_EQ(deviceSupport.supportsActivator(), false);
    EXPECT_EQ(deviceSupport.supportsMouse(), false);
    EXPECT_EQ(deviceSupport.supportsTrackball(), false);
    EXPECT_EQ(deviceSupport.supportsTablet(), false);
    EXPECT_EQ(deviceSupport.supportsPaddle(), false);
    EXPECT_EQ(deviceSupport.supportsKeyboard(), false);
    EXPECT_EQ(deviceSupport.supportsRS232(), false);
    EXPECT_EQ(deviceSupport.supportsPrinter(), false);
    EXPECT_EQ(deviceSupport.supportsCDROM(), false);
    EXPECT_EQ(deviceSupport.supportsFloppyDrive(), false);
    EXPECT_EQ(deviceSupport.supportsDownload(), false);
}

TEST(DeviceSupportTestSuite, getDeviceSupportMultiple) {
    std::string raw_data = "J6GC";
    support::DeviceSupport deviceSupport(raw_data);

    EXPECT_EQ(deviceSupport.supportsThreeButtonController(), true);
    EXPECT_EQ(deviceSupport.supportsSixButtonController(), true);
    EXPECT_EQ(deviceSupport.supportMasterSystemController(), false);
    EXPECT_EQ(deviceSupport.supportsAnalogJoystick(), false);
    EXPECT_EQ(deviceSupport.supportsMultitap(), false);
    EXPECT_EQ(deviceSupport.supportsLightGun(), true);
    EXPECT_EQ(deviceSupport.supportsActivator(), false);
    EXPECT_EQ(deviceSupport.supportsMouse(), false);
    EXPECT_EQ(deviceSupport.supportsTrackball(), false);
    EXPECT_EQ(deviceSupport.supportsTablet(), false);
    EXPECT_EQ(deviceSupport.supportsPaddle(), false);
    EXPECT_EQ(deviceSupport.supportsKeyboard(), false);
    EXPECT_EQ(deviceSupport.supportsRS232(), false);
    EXPECT_EQ(deviceSupport.supportsPrinter(), false);
    EXPECT_EQ(deviceSupport.supportsCDROM(), true);
    EXPECT_EQ(deviceSupport.supportsFloppyDrive(), false);
    EXPECT_EQ(deviceSupport.supportsDownload(), false);
}

TEST(DeviceSupportTestSuite, getDeviceSupportAll) {
    std::string raw_data = "J60A4GLMBTVKRPCFD";
    support::DeviceSupport deviceSupport(raw_data);

    EXPECT_EQ(deviceSupport.supportsThreeButtonController(), true);
    EXPECT_EQ(deviceSupport.supportsSixButtonController(), true);
    EXPECT_EQ(deviceSupport.supportMasterSystemController(), true);
    EXPECT_EQ(deviceSupport.supportsAnalogJoystick(), true);
    EXPECT_EQ(deviceSupport.supportsMultitap(), true);
    EXPECT_EQ(deviceSupport.supportsLightGun(), true);
    EXPECT_EQ(deviceSupport.supportsActivator(), true);
    EXPECT_EQ(deviceSupport.supportsMouse(), true);
    EXPECT_EQ(deviceSupport.supportsTrackball(), true);
    EXPECT_EQ(deviceSupport.supportsTablet(), true);
    EXPECT_EQ(deviceSupport.supportsPaddle(), true);
    EXPECT_EQ(deviceSupport.supportsKeyboard(), true);
    EXPECT_EQ(deviceSupport.supportsRS232(), true);
    EXPECT_EQ(deviceSupport.supportsPrinter(), true);
    EXPECT_EQ(deviceSupport.supportsCDROM(), true);
    EXPECT_EQ(deviceSupport.supportsFloppyDrive(), true);
    EXPECT_EQ(deviceSupport.supportsDownload(), true);
}