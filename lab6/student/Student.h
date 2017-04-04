//
// Created by bruzpatr on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class StudyYear {
    StudyYear &operator++();
};
class Student {
    string id;
    string first_name;
    string last_name;
    string program;
    StudyYear year;
};
#endif //JIMP_EXERCISES_STUDENT_H
