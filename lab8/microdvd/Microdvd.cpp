//
// Created by patrycja on 03.05.17.
//

#include "Microdvd.h"
#include <fstream>
using namespace std;
MicroDVD::MicroDVD(std::string in_path, std::string out_path) {
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
void MicroDVD::delay(int delay, int fps) {
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
            iFrameNumber+=delay*fps;
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