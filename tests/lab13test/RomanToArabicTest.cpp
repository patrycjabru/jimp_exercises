//
// Created by mwypych on 01.06.17.
//
#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"
#include <string>
#include <gtest/gtest.h>

class RomanToArabicTest : public ::testing::Test, MemLeakTest {
public:
};
TEST_F(RomanToArabicTest, RomanToArabic1) {
    EXPECT_EQ(1, RomanToArabic("I"));
    EXPECT_EQ(4, RomanToArabic("IV"));
    EXPECT_EQ(9, RomanToArabic("IX"));
}
TEST_F(RomanToArabicTest, RomanToArabic2) {
    EXPECT_EQ(16, RomanToArabic("XVI"));
    EXPECT_EQ(19, RomanToArabic("XIX"));
    EXPECT_EQ(13, RomanToArabic("XIII"));
}
TEST_F(RomanToArabicTest, RomanToArabic3) {
    EXPECT_EQ(28, RomanToArabic("XXVIII"));
    EXPECT_EQ(97, RomanToArabic("XCVII"));
    EXPECT_EQ(88, RomanToArabic("LXXXVIII"));
}
TEST_F(RomanToArabicTest, RomanToArabic4) {
    EXPECT_EQ(852, RomanToArabic("DCCCLII"));
    EXPECT_EQ(416, RomanToArabic("CDXVI"));
    EXPECT_EQ(749, RomanToArabic("DCCXLIX"));
}
TEST_F(RomanToArabicTest, Error) {
    EXPECT_EQ(-1, RomanToArabic("FLII"));
    EXPECT_EQ(-1, RomanToArabic("ifdsI"));
    EXPECT_EQ(-1, RomanToArabic("0njk"));
}
