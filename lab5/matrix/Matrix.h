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
        Matrix(int rows,int cols);
        Matrix(string input);
        string print();
        Matrix add(Matrix m2);
        Matrix sub(Matrix m2);
        Matrix mul(Matrix m2);
        complex<double> determinant(int i,int j);
        Matrix div(Matrix m2);
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
