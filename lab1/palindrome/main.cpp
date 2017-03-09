#include "Palindrome.h"
#include <iostream>
using namespace std;
int main(int value) {
    int odp;
    string str;
    cout << "1. sprawdz czy jest palindromem\n2. wyjscie";
    do
    {
        cin >> odp;
    }
    while (odp!=1 and odp!=2);
    if (odp==1)
    {
        cout << "Podaj tekst do sprawdzdenia";
        cin >> str;
        if (is_palindrome(str)==true)
        {
            cout <<"Jest palindromem";
        }
        else
        {
            cout << "Nie jest palindromem";
        }
    }
    return 0;
}
