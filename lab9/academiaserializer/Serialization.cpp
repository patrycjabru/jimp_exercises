//
// Created by bodzbarb on 09.05.17.
//

#include "Serialization.h"

namespace academia {
    void Room::Serialize(Serializer *serialize) {

    }

    Room::Room(int it_, const std::string &name_, Room::Type type_) : it_(it_), name_(name_), type_(type_) {

    }

    void Serializable::Serialize(Serializer *) {

    }
    Serializer::Serializer(std::ostream *out) {

    }
};