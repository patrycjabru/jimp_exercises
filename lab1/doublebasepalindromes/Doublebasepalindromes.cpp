//
// Created by patrycja on 02.03.17.
//

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
        is_palindrome = true;               //domyslnie palindrom true
        string str = to_string(max_value);  //zamiana biezacej wartosci sprawdzanej liczby na string
        j = str.length() - 1;               //ostatnia cyfra
        i = 0;                              //pierwsza cyfra
        while (j > i)
        {
            if (str[i] != str[j]) {         //jesli jakies wartosci nie sa rowne to nie jest palindromem
                is_palindrome = false;
                break;
            }
            i++;
            j--;
        }

        if (is_palindrome) {            //jesli jest palindromem w dziesietnym to sprawdza w binarnym
            int dec = max_value;        //biezaca wartosc zapisuje do dec
            string bin_str = "";        //tworzy pusty string
            while (dec > 0) {           //zamiana na binarny
                bin_str = bin_str + (to_string(dec % 2));   //rozszerza string o nowa binarna cyfre
                dec = dec / 2;
            }
            i = 0;                      //ponownie sprawdzamy czy jest palindromem
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