//
// Created by bruzpatr on 23.05.17.
//

#include <iostream>
#include "Mean.h"

int main() {

    std::vector<double> v1 ={1,2};
    double result1 = Mean<double>(v1);
    std::cout << result1 << "\n";
    std::vector<int> v2 ={1,2};
    double result2 = Mean<int>(v2);
    std::cout << result2 << "\n";
    std::complex<double> a;
    std::complex<double> b;
    a.real(1);
    a.imag(0);
    b.real(2);
    b.imag(2);
    std::vector<std::complex<double>> v3 ={a,b};
    std::complex<double> result3 = Mean<std::complex<double>>(v3);
    std::cout << result3;
    return 0;
}