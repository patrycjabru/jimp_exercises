//
// Created by patrycja on 31.03.17.
//
#include <iostream>
#include "TextPool.h"

using namespace pool;
using namespace std;

int main() {
    //Inicjalizacja wstępna puli za pomocą listy inicjalizacyjnej
    TextPool pool {"abc", "efg", "hij", "klmn", "oprst", "abc"};

    //wstawienie napisu do puli
    auto s1 = pool.Intern("efgh");
    auto s3 = pool.Intern("efgh");
    //wstawienie kolejnego napisu do puli (w obu przypadkach nie
    //powinien się zmienić rozmiar puli)
    auto s2 = pool.Intern("efg");
//
    cout << (s1 == s3 ? "True" : "False") << endl; //uchwyty są tymi samymi napisami co do wartości
    cout << pool.StoredStringCount() << endl; // w puli jest wciąż 5 napisów
    cout << (s1.begin() == s2.begin() ? "True" : "False") << endl; //na dodatek uchywyty s1 i s2 pokazują dokładnie na ten sam napis w puli (wskaźniki są identyczne)
}