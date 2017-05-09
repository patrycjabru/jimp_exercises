//
// Created by bodzbarb on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H

#include <iostream>
#include <vector>
#include <initializer_list>

namespace academia {
    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    };

    class Serializable {
    public:
        virtual void Serialize(Serializer *)=0;

    };

    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB
        };

        Room(int it_, const std::string &name_, Type type_);

        void Serialize(Serializer *serialize) override;

    private:
        int id_;
        std::string name_;
        Type type_;
    };
};

#endif //JIMP_EXERCISES_SERIALIZER_H
