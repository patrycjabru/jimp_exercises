//
// Created by patrycja on 03.05.17.
//

#include "MovieSubtitles.h"
#include <memory>
using namespace moviesubs;
int main() {
//    try {
    MicroDvdSubtitles m("/home/patrycja/CLion/exercises/lab1/exercises_aaa/lab8/moviesubtitles/test1_in",
                   "/home/patrycja/CLion/exercises/lab1/exercises_aaa/lab8/moviesubtitles/test1_out");
//    } catch() {}
    m.delay(12000,50);
    for (int i=0;i<2048;i++) {
        std::cout << m._in[i];
    }
    std::cout << "\n";
    for (int i=0;i<2048;i++) {
        std::cout << m._out[i];
    }
    auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);

//    m.ShiftAllSubtitlesBy(12000,50,)
    return 0;
}