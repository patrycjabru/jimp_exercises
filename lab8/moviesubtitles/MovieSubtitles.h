//
// Created by patrycja on 03.05.17.
//

#ifndef JIMP_EXERCISES_MICRODVD_H
#define JIMP_EXERCISES_MICRODVD_H
#define MAX 2048
#include <iostream>
#include <sstream>
#include <istream>
#include <stdexcept>

namespace moviesubs {
    class MicroDvdSubtitles {
    public:
        MicroDvdSubtitles() = default;
        MicroDvdSubtitles(std::string in_path, std::string out_path);
        void delay(int delay, int fps);
        void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in,std::stringstream *out);
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

    class MicroDvdError : public std::runtime_error
    {
    public:
        int LineAt() const {
            return line;
        }
        MicroDvdError(std::string str, int line) : line(line), std::runtime_error(str) {}

    private:
        int line;
    };

    class NegativeFrameAfterShift : public MicroDvdError {
    public:
        NegativeFrameAfterShift(std::string str, int line);
    };

    class SubtitleEndBeforeStart : public MicroDvdError {
    public:
        SubtitleEndBeforeStart(std::string str, int line);
    };

    class InvalidSubtitleLineFormat : public MicroDvdError {
    public:
        InvalidSubtitleLineFormat(std::string str, int line);
    };
}
#endif //JIMP_EXERCISES_MICRODVD_H
