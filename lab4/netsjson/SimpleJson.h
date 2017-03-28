//
// Created by patrycja on 22.03.17.
//
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
namespace nets {
    class JsonValue {
    private:
        double dValue;
        int iValue;
        std::string sValue;
        bool bValue;
        std::vector<JsonValue> vValue;
        std::map<std::string, JsonValue> mValue;
        int whichValue = 0;
    public:
        JsonValue(double value);

        JsonValue(int value);

        JsonValue(std::string value);

        JsonValue(bool value);

        JsonValue(std::vector<JsonValue> vec);

        JsonValue(std::map<std::string, JsonValue> map);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
