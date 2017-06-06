//
// Created by mwypych on 01.06.17.
//
#include "ArabicRoman.h"
#include <iostream>
#include <gtest/gtest.h>
#include <MemLeakTest.h>

class ArabicToRomanTest : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(ArabicToRomanTest, ArabicToRoman1) {
    EXPECT_EQ("I", ArabicToRoman(1));
    EXPECT_EQ("II", ArabicToRoman(2));
    EXPECT_EQ("IV", ArabicToRoman(4));
}
TEST_F(ArabicToRomanTest, ArabicToRoman2) {
    EXPECT_EQ("XXIX", ArabicToRoman(29));
    EXPECT_EQ("L", ArabicToRoman(50));
    EXPECT_EQ("XL", ArabicToRoman(40));
}
TEST_F(ArabicToRomanTest, ArabicToRoman3) {
    EXPECT_EQ("C", ArabicToRoman(100));
    EXPECT_EQ("D", ArabicToRoman(500));
    EXPECT_EQ("CD", ArabicToRoman(400));
}
TEST_F(ArabicToRomanTest, ArabicToRoman4) {
    EXPECT_EQ("MM", ArabicToRoman(2000));
    EXPECT_EQ("CM", ArabicToRoman(900));
}
TEST_F(ArabicToRomanTest, ArabicToRoman5) {
    EXPECT_EQ("Invalid Roman Number Value", ArabicToRoman(4000));
    EXPECT_EQ("Invalid Roman Number Value", ArabicToRoman(-10));
}
TEST_F(ArabicToRomanTest, ArabicToRoman6) {
    EXPECT_EQ("CXXXVI", ArabicToRoman(136));
}

