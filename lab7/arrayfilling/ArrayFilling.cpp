//
// Created by bruzpatr on 11.04.17.
//

#include "ArrayFilling.h"

void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}

int UniformFill::Value(int index) const {
    return value_;
}
int IncrementFill::Value(int index) const {
    return value_+increm;
}
int RandomFill::Value(int index) const {
    srand(time(NULL));
    int r=(std::rand()%100);
    return r;
}
int SquareFill::Value(int index) const {
    int a=4;
    int b=12;
    return a*(index*index)+b;
}
