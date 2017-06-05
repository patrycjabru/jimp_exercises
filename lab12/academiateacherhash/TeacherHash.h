//
// Created by patrycja on 05.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>

namespace academia
{

    class TeacherId {
    public:
        TeacherId(const int &value);
        operator int() const{ return this->id_; }
    private:
        int id_;
    };
    class Teacher
    {
    public:
        Teacher(const TeacherId &id, std::string name, std:: string department);
        TeacherId Id() const {return id_; }
        std::string Name() const {return name_; }
        std::string Department() const {return department_; }
        bool operator == (const Teacher& t) const;
        bool operator != (const Teacher& t) const;
    private:
        std::string name_;
        std::string department_;
        TeacherId id_=0;
    };
    class TeacherHash {
    public:
        int operator()(const Teacher &teacher) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
