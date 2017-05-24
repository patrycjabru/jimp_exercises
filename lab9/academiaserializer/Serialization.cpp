//
// Created by bruzpatr on 09.05.17.
//

#include "Serialization.h"
namespace academia {
    void Room::Serialize(Serializer *serializer) {
        Serializable::Serialize(serializer);
    }

    Room::Room(int id, const std::string &name, Room::Type type) : id(id), name(name), type(type) {}

    void Serializable::Serialize(Serializer *) {

    }

    Serializer::Serializer(std::ostream *out) {

    }
}
