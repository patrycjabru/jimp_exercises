//
// Created by patrycja on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include<iostream>
#include <complex>
using namespace std;
namespace matrix{
    class Matrix {
    private:
        complex<double> **array;
    public:
        Matrix();
        Matrix(string input);
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
