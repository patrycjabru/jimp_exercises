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
    s.first_name="Arkadiusz";
    s.last_name="Kowalski";
    s.program="informatyka";
    sy.year=2;
    cout << s.year.year << endl;
    ++s.year;
    cout << s.year.year << endl;
    --s.year;
    cout << s.year.year << endl;
    cin >> sy;
    return  0;
}