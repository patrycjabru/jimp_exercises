//
// Created by bodzbarb on 06.06.17.
//

#include <iostream>
#include "ArabicRoman.h"

std::string ArabicToRoman(int value) {
    if(value<=0)
        return "error";
    struct romandata_t { unsigned int value; char const* numeral; };
    const struct romandata_t romandata[] =
            {
                    {1000, "M"}, {900, "CM"},
                    {500, "D"}, {400, "CD"},
                    {100, "C"}, { 90, "XC"},
                    { 50, "L"}, { 40, "XL"},
                    { 10, "X"}, { 9, "IX"},
                    { 5, "V"}, { 4, "IV"},
                    { 1, "I"},
                    { 0, NULL} // end marker
            };
    std::string result;
    for (const romandata_t* current = romandata; current->value > 0; ++current)
    {
        while (value >= current->value)
        {
            result += current->numeral;
            value -= current->value;
        }
    }
    return result;
}

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int RomanToArabic(std::string str)
{
    int res = 0;
    for (int i=0; i < str.length(); i++)
    {
        int s1 = value(str[i]);
        if(s1==-1)
            return -1;
        if (i+1 < str.length())
        {
            int s2 = value(str[i+1]);
            if (s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}