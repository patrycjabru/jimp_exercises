//void delay()
// Created by patrycja on 03.05.17.
//

#ifndef JIMP_EXERCISES_MICRODVD_H
#define JIMP_EXERCISES_MICRODVD_H
#define MAX 2048
#include <iostream>
namespace moviesubs {
    class MicroDVD {
    public:
        MicroDVD() = default;
        MicroDVD(std::string in_path, std::string out_path);
        void delay(int delay, int fps);
//private:
        char _in[MAX];
        char _out[MAX];
    };

    class CannotFindInputFile {
    public:
        CannotFindInputFile();
    };

    class CannotFindOutputFile {
    public:
        CannotFindOutputFile();
    };

    class OutputFileIsntEmpty {
    public:
        OutputFileIsntEmpty();
    };

    class TooLongInputFile {
    public:
        TooLongInputFile();
    };

    class InvalidFormat {
    public:
        InvalidFormat();
    };

    class TooLongOutput {
    public:
        TooLongOutput();
    };
}
#endif //JIMP_EXERCISES_MICRODVD_H
