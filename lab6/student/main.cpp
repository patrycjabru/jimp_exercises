//
// Created by bruzpatr on 04.04.17.
//
#include <Student.h>

using namespace std;
int main() {
    Student s;
    StudyYear sy;
    string str;
    s.year.year=2;
    s.id="2030001234";
    try {
        s.setFirstName("A");
    }catch(invalidName a){}
    s.last_name="Kowalski";
    try {
    s.setProgram("informatykaaa");
    }catch(invalidProg a){}
    try {
        s.setAge(1);
    }catch(invalidAge a){}
    sy.year=2;
    cout << s.year.year << endl;
    ++s.year;
    cout << s.year.year << endl;
    --s.year;
    cout << s.year.year << endl;
//    cin >> sy;
    return  0;
}