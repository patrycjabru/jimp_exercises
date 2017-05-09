//
// Created by bodzbarb on 09.05.17.
//

#include "Serialization.h"

namespace academia {
    void Room::Serialize(Serializer *serializer) {
        serializer->Header("test1");
        serializer->IntegerField("id",this->id_);
        serializer->StringField("name",this->name_);
        serializer->StringField("type",this->name_);
        serializer->Footer("test1");
    }

    Room::Room(int it_, const std::string &name_, Room::Type type_) : it_(it_), name_(name_), type_(type_) {

    }

    void Serializable::Serialize(Serializer *) {

    }
    Serializer::Serializer(std::ostream *out) {

    }
};