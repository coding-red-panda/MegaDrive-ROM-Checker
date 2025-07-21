#include "gtest/gtest.h"
#include "rom.h"

TEST(RomTestSuite, GetSystemTypeEU) {
    const Rom rom("resources/Aladdin.md");

    const std::string systemType = rom.getSystemType();
    EXPECT_EQ(systemType, "SEGA MEGA DRIVE");
}

TEST(RomTestSuite, GetSystemTypeUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const std::string systemType = rom.getSystemType();
    EXPECT_EQ(systemType, "SEGA GENESIS");
}

TEST(RomTestSuite, GetSystemTypeJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const std::string systemType = rom.getSystemType();
    EXPECT_EQ(systemType, "SEGA MEGA DRIVE");
}

TEST(RomTestSuite, GetCopyrightAndReleaseDateEU) {
    const Rom rom("resources/Aladdin.md");

    const support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "SEGA");
    EXPECT_EQ(copyright.getYear(), 1993);
    EXPECT_EQ(copyright.getMonth(), "AUG");
}

TEST(RomTestSuite, GetCopyrightAndReleaseDateUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "SEGA");
    EXPECT_EQ(copyright.getYear(), 1993);
    EXPECT_EQ(copyright.getMonth(), "NOV");
}

TEST(RomTestSuite, GetCopyrightAndReleaseDateJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "NCS");
    EXPECT_EQ(copyright.getYear(), 1992);
    EXPECT_EQ(copyright.getMonth(), "JAN");
}

TEST(RomTestSuite, GetDomesticTitleEU) {
    const Rom rom("resources/Aladdin.md");

    const std::string title = rom.getDomesticTitle();
    EXPECT_EQ(title, "ALADDIN");
}

TEST(RomTestSuite, GetDomesticTitleUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const std::string title = rom.getDomesticTitle();
    EXPECT_EQ(title, "SONIC THE HEDGEHOG 3");
}

TEST(RomTestSuite, GetDomesticTitleJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const std::string title = rom.getDomesticTitle();
    EXPECT_EQ(title, "SORCER KINGDOM");
}

TEST(RomTestSuite, GetSerialNumberEU) {
    const Rom rom("resources/Aladdin.md");

    const support::SerialNumber serial = rom.getSerialNumber();
    EXPECT_EQ(serial.toString(), "GM MK-1058 -00");
}

TEST(RomTestSuite, GetSerialNumberUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const support::SerialNumber serial = rom.getSerialNumber();
    EXPECT_EQ(serial.toString(), "GM MK-1079 -00");
}

TEST(RomTestSuite, GetSerialNumberJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const support::SerialNumber serial = rom.getSerialNumber();
    EXPECT_EQ(serial.toString(), "GM T-25113 -00");
}

TEST(RomTestSuite, GetChecksumEU) {
    const Rom rom("resources/Aladdin.md");

    const unsigned short checksum = rom.getChecksum();
    EXPECT_EQ(checksum, 0xA5E3);
}

TEST(RomTestSuite, GetChecksumUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const unsigned short checksum = rom.getChecksum();
    EXPECT_EQ(checksum, 0xA8F2);
}

TEST(RomTestSuite, GetChecksumJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const unsigned short checksum = rom.getChecksum();
    EXPECT_EQ(checksum, 0xB8F7);
}

TEST(RomTestSuite, calculateChecksumEU) {
    const Rom rom("resources/Aladdin.md");

    const unsigned short checksum = rom.getChecksum();
    const unsigned short calculatedChecksum = rom.calculateChecksum();

    EXPECT_EQ(checksum, calculatedChecksum);
}

TEST(RomTestSuite, calculateChecksumUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const unsigned short checksum = rom.getChecksum();
    const unsigned short calculatedChecksum = rom.calculateChecksum();

    EXPECT_EQ(checksum, calculatedChecksum);
}

// The ROM "Sorcer Kingdom.md" is known to have an non-standard checksum.
// This test is to ensure that the checksum calculation works correctly
TEST(RomTestSuite, calculateChecksumJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const unsigned short calculatedChecksum = rom.calculateChecksum();

    EXPECT_EQ(calculatedChecksum, 0xC9BE);
}

TEST(RomTestSuite, getDeviceSupportEU) {
    const Rom rom("resources/Aladdin.md");
    const support::DeviceSupport deviceSupport = rom.getDeviceSupport();

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

TEST(RomTestSuite, getDeviceSupportUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");
    const support::DeviceSupport deviceSupport = rom.getDeviceSupport();

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

TEST(RomTestSuite, getDeviceSupportJP) {
    const Rom rom("resources/Sorcer Kingdom.md");
    const support::DeviceSupport deviceSupport = rom.getDeviceSupport();

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