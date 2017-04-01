//
// Created by patrycja on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include<iostream>
#include <complex>
#include <cstring>
using namespace std;
namespace matrix{
    class Matrix {
    private:
        complex<double> **array;
        int rows;
        int cols;
    public:
        Matrix();
        Matrix(string input);
        string print();
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
