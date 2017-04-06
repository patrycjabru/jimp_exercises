//
// Created by patrycja on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include<iostream>
#include <complex>
#include <cstring>
#include <vector>

using namespace std;
namespace algebra{
    class Matrix {
    private:
        complex<double> **array;
        int rows;
        int cols;
        std::vector<std::vector<std::complex<double>>> data;
    public:
        Matrix();
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &m);
        Matrix(int rows,int cols);
        Matrix(string input);
        Matrix(const Matrix &m);
        ~Matrix();
        string Print() const;
        Matrix Add(Matrix m2) const;
        Matrix Sub(Matrix m2);
        Matrix Mul(Matrix m2);
        complex<double> Determinant(int i,int j);
        Matrix Div(Matrix m2);
        pair<size_t, size_t > Size();
        Matrix Pow(int p);
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
