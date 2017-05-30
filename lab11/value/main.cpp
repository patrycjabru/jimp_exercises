#include <iostream>
#include <memory>
#include "Value.h"

//
// Created by bruzpatr on 23.05.17.
//
int main() {
    int* p=0;
    int a=5;
    p=&a;
    std::cout << Ptr(p);

    auto sp = std::make_shared<int>(a);
    std::cout << Ptr(sp);

    return 0;
}
