#include "MovieSubtitles.h"
#include <fstream>
#include <string>
using namespace moviesubs;
using namespace std;

MicroDvdSubtitles::MicroDvdSubtitles(std::string in_path, std::string out_path) {
    ifstream in_file(in_path);
    char ch;
    if(!in_file)
        throw CannotFindInputFile();
    int i=0;
    while (in_file >> ch) {
        if(i==MAX)
            throw TooLongInputFile();
        _in[i]=ch;
        i++;
    }
    while (i<MAX) {
        _in[i]=NULL;
        i++;
    }
    in_file.close();
    ifstream out_file(out_path);
    if(!out_file)
        throw CannotFindOutputFile();
    if(in_file >> ch) {
        throw OutputFileIsntEmpty();
    }
    out_file.close();
    i=0;
    while(i<MAX) {
        _out[i]=NULL;
        i++;
    }
}
void MicroDvdSubtitles::delay(int delay, int fps) {
    if (fps < 0)
        throw invalid_argument("Invalid Framerate");
    std::string sFrameNumber="";
    int iFrameNumber;
    bool isFrameNumber=false;
    bool recalculate=false;
    int j=0;
    for(int i=0;i<MAX;i++) {
        if (_in[i]=='}') {
            isFrameNumber=false;
            recalculate=true;
        }
        if (isFrameNumber) {
            sFrameNumber+=_in[i];
        }
        if (_in[i]=='{')
            isFrameNumber=true;
        if (recalculate){
            for (auto s : sFrameNumber)
                if (s<48 or s>57)
                    throw InvalidFormat();
//            cout << sFrameNumber << "\n";
            iFrameNumber=stoi(sFrameNumber);
            iFrameNumber+=delay*fps/1000;
            if(iFrameNumber<0)
                throw NegativeFrameAfterShift();
            sFrameNumber=to_string(iFrameNumber);
            sFrameNumber='{'+sFrameNumber; // tu tez
            for (auto c : sFrameNumber) {
                if (j==MAX)
                    throw TooLongOutput();
                _out[j] = c;
                j++;
            }
            sFrameNumber="";
            recalculate=false;
        }
        if (!recalculate and !isFrameNumber) {
            _out[j]=_in[i];
            j++;

        }
    }
}

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
    if (fps < 0)
        throw invalid_argument("Invalid Framerate");
    std::string inputString = in->str();
    std::string outputString="";
    std::string sFrameNumber="";
    int iFrameNumber;
    bool isFrameNumber=false;
    bool recalculate=false;
    for (auto c : inputString) {
        if (c == '}') {
            recalculate = true;
            isFrameNumber = false;
        }
        if (isFrameNumber) {
            sFrameNumber += c;
        }
        if (c == '{') {
            isFrameNumber = true;
        }
        if (recalculate) {
            for (auto s : sFrameNumber)
                if (s < 48 or s > 57)
                    throw InvalidFormat();
            cout << sFrameNumber << "\n";
            iFrameNumber = stoi(sFrameNumber);
            iFrameNumber += delay * fps / 1000;
            sFrameNumber = to_string(iFrameNumber);
            sFrameNumber = '{' + sFrameNumber; // tu tez
//            for (auto c : sFrameNumber) {
//                if (j==MAX)
//                    throw TooLongOutput();
//                _out[j] = c;
//                j++;
            outputString += sFrameNumber;
            sFrameNumber = "";
            recalculate = false;
        }
        if (!recalculate and !isFrameNumber) {
            outputString += c;
        }

    }
    *out << outputString;
}

CannotFindInputFile::CannotFindInputFile() {
    cout << "Nie mozna odnalezc pliku wejsciowego";
}
CannotFindOutputFile::CannotFindOutputFile() {
    cout << "Nie mozna odnalezc pliku wyjsciowego";
}
OutputFileIsntEmpty::OutputFileIsntEmpty() {
    cout << "Plik wyjsciowy nie jest pusty";
}
TooLongInputFile::TooLongInputFile() {
    cout << "Za dlugi plik wejsciowy";
}
InvalidFormat::InvalidFormat() {
    cout << "Zly format napisow";
}
TooLongOutput::TooLongOutput() {
    cout << "Zbyt dlugie wyjscie";
}

NegativeFrameAfterShift::NegativeFrameAfterShift(std::string str, int line) : MicroDvdError(
        "At line " + std::to_string(line) + ": " + str, line) {};

SubtitleEndBeforeStart::SubtitleEndBeforeStart(std::string str, int line) : MicroDvdError(
        "At line " + std::to_string(line) + ": " + str, line) {};

InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(std::string str, int line) : MicroDvdError(
        "At line " + std::to_string(line) + ": " + str, line) {};
