//
// Created by mwypych on 01.06.17.
//
#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"
#include <iostream>
#include <gtest/gtest.h>

class RomanToArabicTest : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(RomanToArabicTest, RomanToArabic1) {
    EXPECT_EQ(1, RomanToArabic("I"));
    EXPECT_EQ(2, RomanToArabic("II"));
    EXPECT_EQ(3, RomanToArabic("III"));
}
TEST_F(RomanToArabicTest, RomanToArabic2) {
    EXPECT_EQ(10, RomanToArabic("X"));
    EXPECT_EQ(19, RomanToArabic("XIX"));
    EXPECT_EQ(47, RomanToArabic("XLVII"));
}
TEST_F(RomanToArabicTest, RomanToArabic3) {
    EXPECT_EQ(136, RomanToArabic("CXXXVI"));
}
TEST_F(RomanToArabicTest, RomanToArabic4) {
    EXPECT_EQ(0, RomanToArabic(""));
}
