//
// Created by bruzpatr on 04.04.17.
//

#include "Student.h"
#include <istream>
using namespace std;
void Student::setAge(int age) {
    if (age<10 or age>100)
        throw invalidAge();
    this->age=age;
}
void Student::setFirstName(string name) {
    if (name.length()<2)
        throw invalidName();
    if (name[0]<65 or name[0]>90)
        throw invalidName();
    for (int i=1;i<name.length();i++) {
        if (name[i]<97 or name[i]>122)
            throw invalidName();
    }
    first_name=name;
}
void Student::setProgram(string prog) {
    if (prog!="informatyka" and prog!="ekonomia" and prog!="matematyka" and prog!="fizyka" and prog!="filozofia")
        throw invalidProg();
    program=prog;
}
invalidAge::invalidAge(){
    cout<<"Zly wiek";
}
invalidName::invalidName(){
    cout<<"Zle imie";
}
invalidProg::invalidProg(){
    cout<<"Zly kierunek";
}