#include "Doublebasepalindromes.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
uint64_t DoubleBasePalindromes(int max_value) {
    int i;
    uint64_t suma = 0;
    bool is_palindrome;
    long int j;
    while (max_value > 0)
    {
        is_palindrome = true;
        string str = to_string(max_value);
        j = str.length() - 1;
        i = 0;
        while (j > i)
        {
            if (str[i] != str[j]) {
                is_palindrome = false;
                break;
            }
            i++;
            j--;
        }

        if (is_palindrome) {
            int dec = max_value;
            string bin_str = "";
            while (dec > 0) {
                bin_str = bin_str + (to_string(dec % 2));
                dec = dec / 2;
            }
            i = 0;
            j = bin_str.length() - 1;
            while (j > i) {
                if (bin_str[i] != bin_str[j]) {
                    is_palindrome = false;
                    break;
                }
                i++;
                j--;

            }
        }
        if (is_palindrome)
        {
            suma = suma + max_value;
        }
        max_value--;
    }
    return suma;
}