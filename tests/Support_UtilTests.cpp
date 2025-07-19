#include "gtest/gtest.h"
#include "support/Util.h"

TEST(UtilTestSuite, TrimLeadingSpaces) {
    std::string str = "  Hello World!";
    Support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimDoubleSpaces) {
    std::string str = "Hello  World!";
    Support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimTrailingSpaces) {
    std::string str = "Hello World!  ";
    Support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimFullSpaces) {
    std::string str = "  Hello    World!  ";
    Support::Util::trim(str);
    EXPECT_EQ(str, "Hello World!");
}

TEST(UtilTestSuite, TrimTrailingNewlines) {
    std::string str = "Hello\nWorld!\n";
    Support::Util::trim(str);
    EXPECT_EQ(str, "Hello\nWorld!");
}