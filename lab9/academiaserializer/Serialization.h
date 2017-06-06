//
// Created by bruzpatr on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H

#include <iostream>
#include <vector>
#include <functional>
#include <initializer_list>


namespace academia {
    class Serializable;

    class Serializer {
    public:
//        virtual
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    };
    class Serializable {
    public:
        virtual void Serialize(Serializer *);
        };
    class Room : public Serializable {
    public:
        enum class Type{
            COMPUTER_LAB
        };
        Room(int id, const std::string &name, Type type);

        void Serialize(Serializer *serialize) override;
    private:
        int id;
        std::string name;
        Type type;
    };
};
#endif //JIMP_EXERCISES_SERIALIZER_H
