
//
// Created by patrycja on 01.04.17.
//
#include <iostream>
#include "Matrix.h"
using namespace algebra;
using namespace std;

int main(int argc, char* argv[]) {
    cout << "vob";
    Matrix m1(argv[1]);
    Matrix m2(argv[2]);
    Matrix m3(argv[3]);

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
//    cout << "Wyznacznik" << m3.Determinant(3,3) << endl;
//    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
//    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
}