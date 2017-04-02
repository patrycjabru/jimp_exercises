//
// Created by patrycja on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include<iostream>
#include <complex>
#include <cstring>

using namespace std;
namespace algebra{
    class Matrix {
    private:
        complex<double> **array;
        int rows;
        int cols;
    public:
        Matrix();
        Matrix(int rows,int cols);
        Matrix(string input);
        string Print();
        Matrix Add(Matrix m2);
        Matrix Sub(Matrix m2);
        Matrix Mul(Matrix m2);
        complex<double> Determinant(int i,int j);
        Matrix Div(Matrix m2);
        pair<size_t, size_t > Size();
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
