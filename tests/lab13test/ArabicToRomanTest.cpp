//
// Created by mwypych on 01.06.17.
//

#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"
#include <string>
#include <gtest/gtest.h>

class ArabictoRomanTest : public ::testing::Test, MemLeakTest {
public:
};
TEST_F(ArabictoRomanTest, ArabicToRoman1) {
    EXPECT_EQ("I", ArabicToRoman(1));
    EXPECT_EQ("IV", ArabicToRoman(4));
    EXPECT_EQ("IX", ArabicToRoman(9));
}
TEST_F(ArabictoRomanTest, ArabicToRoman2) {
    EXPECT_EQ("XVI", ArabicToRoman(16));
    EXPECT_EQ("XIX", ArabicToRoman(19));
    EXPECT_EQ("XIII", ArabicToRoman(13));
}
TEST_F(ArabictoRomanTest, ArabicToRoman3) {
    EXPECT_EQ("XXVIII", ArabicToRoman(28));
    EXPECT_EQ("XCVII", ArabicToRoman(97));
    EXPECT_EQ("LXXXVIII", ArabicToRoman(88));
}
TEST_F(ArabictoRomanTest, ArabicToRoman4) {
    EXPECT_EQ("DCCCLII", ArabicToRoman(852));
    EXPECT_EQ("CDXVI", ArabicToRoman(416));
    EXPECT_EQ("DCCXLIX", ArabicToRoman(749));
}
TEST_F(ArabictoRomanTest, NegativeNumber) {
    EXPECT_EQ("error", ArabicToRoman(-1));
    EXPECT_EQ("error", ArabicToRoman(0));
}

