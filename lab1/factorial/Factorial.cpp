//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    int factorial=1;
    if (value>0) {
        for (value; value > 0; value--) {
            factorial = factorial * value;
        }
    }
    if (value<0){
        for (value;value<0;value++)
        {
            factorial=factorial*value;
        }
    }
    return factorial;
}
