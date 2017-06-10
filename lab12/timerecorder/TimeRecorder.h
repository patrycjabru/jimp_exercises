//
// Created by patrycja on 10.06.17.
//

#ifndef JIMP_EXERCISES_TREERECORDER_H
#define JIMP_EXERCISES_TREERECORDER_H
#include <chrono>

namespace profiling{
    template <class T>
    auto TimeRecorder(T arg) {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        auto result = arg();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        auto pair = std::make_pair(result, diff.count() * 1000);
        return pair;
}
}
#endif //JIMP_EXERCISES_TREERECORDER_H
