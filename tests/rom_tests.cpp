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
