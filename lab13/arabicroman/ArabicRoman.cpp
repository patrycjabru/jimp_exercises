//
// Created by bruzpatr on 06.06.17.
//

#include "ArabicRoman.h"
std::string ArabicToRoman(int arabic){
    std::string roman="";
    if (arabic < 1 || arabic > 3999)
        return "Invalid Roman Number Value";
    while (arabic >= 1000) {
        roman += "M";
        arabic -= 1000;        }
    while (arabic >= 900) {
        roman += "CM";
        arabic -= 900;
    }
    while (arabic >= 500) {
        roman += "D";
        arabic -= 500;
    }
    while (arabic >= 400) {
        roman += "CD";
        arabic -= 400;
    }
    while (arabic >= 100) {
        roman += "C";
        arabic -= 100;
    }
    while (arabic >= 90) {
        roman += "XC";
        arabic -= 90;
    }
    while (arabic >= 50) {
        roman += "L";
        arabic -= 50;
    }
    while (arabic >= 40) {
        roman += "XL";
        arabic -= 40;
    }
    while (arabic >= 10) {
        roman += "X";
        arabic -= 10;
    }
    while (arabic >= 9) {
        roman += "IX";
        arabic -= 9;
    }
    while (arabic >= 5) {
        roman += "V";
        arabic -= 5;
    }
    while (arabic >= 4) {
        roman += "IV";
        arabic -= 4;
    }
    while (arabic >= 1) {
        roman += "I";
        arabic -= 1;
    }
    return roman;
}

int RomanToArabic(std::string roman) {
    int arabic=0;
    int arr[roman.size()];
    arr[roman.size()] = 0;
    for (int i=0;i<roman.size();i++) {
        arr[i]=value(roman[i]);
    }
    for (int i=0;i<roman.size();i++) {
        if (arr[i]>=arr[i+1])
            arabic=arabic+arr[i];
        else
            arabic=arabic-arr[i];
    }
    return arabic;
}

int value(char roman) {
    if (roman=='I')
        return 1;
    if (roman=='V')
        return 5;
    if (roman=='X')
        return 10;
    if (roman=='L')
        return 50;
    if (roman=='C')
        return 100;
    if (roman=='D')
        return 500;
    if (roman=='M')
        return 1000;
}
