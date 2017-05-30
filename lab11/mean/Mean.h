//
// Created by bruzpatr on 23.05.17.
//

#ifndef JIMP_EXERCISES_MEAN_H
#define JIMP_EXERCISES_MEAN_H
#include <vector>
#include <complex>
template<class T>
T Mean(const std::vector<T> &v) {
    T suma=0;
    T n=0;
    for (T a:v) {
        suma+=a;
        n+=1;
    }
    return suma/n;
}
#endif //JIMP_EXERCISES_MEAN_H
