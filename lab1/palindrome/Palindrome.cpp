//
// Created by patrycja on 02.03.17.
//

#include "Palindrome.h"
using namespace std;
bool is_palindrome(string str)
{
    bool is_palindrome=true;
    unsigned long int j=str.length()-1;
    int i=0;
    if (str.length()==0)
    {
        return true;
    }
    while (i<j)
    {
        if (str[i]!=str[j])
        {
            is_palindrome=false;
            break;
        }
        i++;
        j--;
    }
    return is_palindrome;
}