#include "gtest/gtest.h"
#include "Rom.h"

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

    const Support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "SEGA");
    EXPECT_EQ(copyright.getYear(), 1993);
    EXPECT_EQ(copyright.getMonth(), "AUG");
}

TEST(RomTestSuite, GetCopyrightAndReleaseDateUS) {
    const Rom rom("resources/Sonic The Hedgehog 3.md");

    const Support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "SEGA");
    EXPECT_EQ(copyright.getYear(), 1993);
    EXPECT_EQ(copyright.getMonth(), "NOV");
}

TEST(RomTestSuite, GetCopyrightAndReleaseDateJP) {
    const Rom rom("resources/Sorcer Kingdom.md");

    const Support::Copyright copyright = rom.getCopyright();

    EXPECT_EQ(copyright.getPublisher(), "NCS");
    EXPECT_EQ(copyright.getYear(), 1992);
    EXPECT_EQ(copyright.getMonth(), "JAN");
}