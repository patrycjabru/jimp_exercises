//
// Created by bruzpatr on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILLING_H
#define JIMP_EXERCISES_ARRAYFILLING_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class ArrayFill {
public:
    virtual int Value(int index) const =0;
};
void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

class UniformFill : public ArrayFill {
public:
    UniformFill(int value = 0) : value_{value} {}
    virtual int Value(int index) const override;
private:
    int value_;
};
class IncrementFill : public ArrayFill {
public:
    IncrementFill(int value = 0,int increment =1 ) : value_{value},increm{increm+increment} {}
    virtual int Value(int index) const override;
private:
    int increm=0;
    int value_;
};
class RandomFill : public ArrayFill {
public:
    RandomFill(int value = 0) : value_{value} {}
    virtual int Value(int index) const override;
private:
    int value_;
};
class SquareFill : public ArrayFill {
public:
    SquareFill(int a,int b) : {}
    virtual int Value(int index) const override;
private:
    int value_;
};
#endif //JIMP_EXERCISES_ARRAYFILLING_H
