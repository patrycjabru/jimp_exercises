//
// Created by patrycja on 22.03.17.
//

#include "SimpleJson.h"
using namespace nets;

JsonValue::JsonValue(double value) {
    dValue = value;
    whichValue = 1;
}

JsonValue::JsonValue(int value) {
    iValue = value;
    whichValue = 2;
}

JsonValue::JsonValue(std::string value) {
    sValue = value;
    whichValue = 3;
}

JsonValue::JsonValue(bool value) {
    bValue = value;
    whichValue = 4;
}

JsonValue::JsonValue(std::vector<JsonValue> vec) {
    vValue = vec;
    whichValue = 5;
}

JsonValue::JsonValue(std::map<std::string, JsonValue> map) {
    mValue = map;
    whichValue = 6;
}


std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
    std::experimental::optional<JsonValue> exp = {};
    std::map<std::string, JsonValue>::const_iterator it;
    auto search = mValue.find(name);
    if (search != mValue.end()) {
        it = mValue.find(name);
        exp = it->second;
    }
    return exp;
}
std::string JsonValue::ToString() const {
    std::string outputStr = "";
    if (whichValue == 1) {
        std::string temp = std::to_string(dValue);
        for (int i = 0; i < temp.length() - 4; i++) {
            outputStr += temp[i];
        }
        return outputStr;
    }
    if (whichValue == 2) {
        outputStr = std::to_string(iValue);
        return outputStr;
    }
    if (whichValue == 3) {
        outputStr = "\"" + sValue + "\"";
        return outputStr;
    }
    if (whichValue == 4) {
        if (bValue == 0)
            outputStr = "false";
        else
            outputStr = "true";
        return outputStr;
    }
    if (whichValue == 5) {
        outputStr = "[";
        for (int i = 0; i < vValue.size(); i++) {
            outputStr += ((vValue[i]).ToString());
            if (i < vValue.size() - 1)
                outputStr += ", ";
        }
        outputStr += "]";
        return outputStr;
    }
    return outputStr;
}