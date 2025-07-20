#include "gtest/gtest.h"
#include "support/util.h"

TEST(UtilTestSuite, TrimLeadingSpaces) {
    std::string str = "  Hello World!";
    support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimDoubleSpaces) {
    std::string str = "Hello  World!";
    support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimTrailingSpaces) {
    std::string str = "Hello World!  ";
    support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimFullSpaces) {
    std::string str = "  Hello    World!  ";
    support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimTrailingNewlines) {
    std::string str = "Hello\nWorld!\n";
    support::Util::trim(str);
    EXPECT_EQ(str, "Hello\nWorld!");
}