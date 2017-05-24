//
// Created by bruzpatr on 11.04.17.
//
#include <ArrayFilling.h>
int main() {
    std::vector<int> vs;
    std::vector<int> vs1;
    std::vector<int> vs2;
    std::vector<int> vs3;
    FillArray(1024, UniformFill {77}, &vs);
//    std::cout << vs[1];
    FillArray(1024, IncrementFill {0,2}, &vs1);
//    std::cout << vs1[0];
    FillArray(1024, RandomFill {0}, &vs2);
//    std::cout << vs2[1];
    FillArray(1024, SquareFill {0}, &vs3);
    std::cout << vs3[1];
    return 0;
}