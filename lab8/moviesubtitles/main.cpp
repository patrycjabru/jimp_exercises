//
// Created by patrycja on 03.05.17.
//

#include "MovieSubtitles.h"
using namespace moviesubs;
int main() {
//    try {
        MicroDVD m("/home/patrycja/CLion/exercises/lab1/exercises_aaa/lab8/moviesubtitles/test1_in",
                   "/home/patrycja/CLion/exercises/lab1/exercises_aaa/lab8/moviesubtitles/test1_out");
//    } catch() {}
    m.delay(12,50);
    for (int i=0;i<2048;i++) {
        std::cout << m._in[i];
    }
    std::cout << "\n";
    for (int i=0;i<2048;i++) {
        std::cout << m._out[i];
    }
    return 0;
}