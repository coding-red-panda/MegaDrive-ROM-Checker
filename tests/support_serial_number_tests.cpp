#include "gtest/gtest.h"
#include "support/serial_number.h"

TEST(SerialNumberSuite, SerialNumberTest) {
    std::string raw = "GM MK-1079 -00  ";
    const auto serial = support::SerialNumber(raw);

    EXPECT_EQ("GM", serial.getType());
    EXPECT_EQ("MK-1079", serial.getSerial());
    EXPECT_EQ(0, serial.getRevision());
}

TEST(SerialNumberSuite, SerialNumberWithRevisionTest) {
    std::string raw = "GM MK-1079 -01  ";
    const auto serial = support::SerialNumber(raw);

    EXPECT_EQ("GM", serial.getType());
    EXPECT_EQ("MK-1079", serial.getSerial());
    EXPECT_EQ(1, serial.getRevision());
}

TEST(SerialNumberSuite, toStringTest) {
    std::string raw = "GM MK-1079 -01  ";
    const auto serial = support::SerialNumber(raw);

    EXPECT_EQ("GM MK-1079 -01", serial.toString());
}

TEST(SerialNumberSuite, toStringExtendedTest) {
    std::string raw = "GM MK-1079 -11  ";
    const auto serial = support::SerialNumber(raw);

    EXPECT_EQ("GM MK-1079 -11", serial.toString());
}

TEST(SerialNumberSuite, toStringCustomTest) {
    std::string raw = "GM MK-1079 -1123";
    const auto serial = support::SerialNumber(raw);

    EXPECT_EQ("GM MK-1079 -1123", serial.toString());
}