//
// Created by bruzpatr on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Student.cpp>
#include <istream>
using namespace std;
class StudyYear {
public:
    int year;
    StudyYear &operator++() {
        ++year;
        return *this;
    }
    StudyYear &operator--() {
        --year;
        return *this;
    }
    void SetYear (int y) {
        year=y;
    }
};
class Student {
public:
    string id;
    string first_name;
    string last_name;
    string program;
    StudyYear year;
};
class StudentRepository {
public:
    vector<Student> vec;
};
std::istream& operator>>(std::istream &is, StudyYear& s);
#endif //JIMP_EXERCISES_STUDENT_H
