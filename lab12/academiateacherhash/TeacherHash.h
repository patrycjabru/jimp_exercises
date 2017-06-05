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
        TeacherId() = default;
        TeacherId(const int &value);
        ~TeacherId()=default;
        operator int() const{ return id_; }
    private:
        int id_;
    };
    class Teacher
    {
    public:
        Teacher() = default;
        Teacher(const TeacherId &id, std::string name, std:: string department);
        ~Teacher()=default;
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
        TeacherHash()= default;
        ~TeacherHash()= default;
        int operator()(const Teacher &t) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
