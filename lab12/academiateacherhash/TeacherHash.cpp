//
// Created by patrycja on 05.06.17.
//

#include "TeacherHash.h"
namespace academia {
    TeacherId::TeacherId(const int &value){
        id_=value;
    }
    Teacher::Teacher(const TeacherId &id, std::string name, std::string department) {
        id_=id;
        name_=name;
        department_=department;
    }
    bool Teacher::operator==(const Teacher &t) const {
        return name_ == t.name_ and department_ == t.department_ and id_ == t.id_;
    }
    bool Teacher::operator!=(const Teacher &t) const {
        return !(name_ == t.name_ and department_ == t.department_ and id_ == t.id_);
    }
    int TeacherHash::operator()(const Teacher &teacher) const {
        return std::hash<int>{}(teacher.Id())^std::hash<std::string>{}(teacher.Name())^std::hash<std::string>{}(teacher.Department());
    }
};