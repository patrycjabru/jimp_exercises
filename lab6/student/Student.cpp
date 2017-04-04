//
// Created by bruzpatr on 04.04.17.
//

#include "Student.h"
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw runtime_error("invalid character");
    }
    is->ignore();
}

//void IgnoreWhitespace(istream* is) {
//    (*is) >> ws;
//}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}
//istream& operator>>(istream & input, StudentRepository& p){
//    CheckNextChar("[Student {id: \"", &input);
//    p.SetX(ReadNumber(&input));
//    CheckNextChar(',', &input);
//    IgnoreWhitespace(&input);
//    p.SetY(ReadNumber(&input));
//    CheckNextChar(')', &input);
//    return input;      // Umożliwia cin >> a >> b >> c;
//}
friend istream& operator>>(istream & input, StudyYear& s){
//    CheckNextChar('', &input);
    s.SetYear(ReadNumber(&input));
//    CheckNextChar(',', &input);
//    IgnoreWhitespace(&input);
//    p.SetY(ReadNumber(&input));
//    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}