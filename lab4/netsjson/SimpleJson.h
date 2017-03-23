//
// Created by patrycja on 22.03.17.
//
#include <experimental/optional>
#include <string>
#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
namespace nets {
    class JsonValue {
    public:
        JsonValue(double value) {
            this->dValue=value;
        }
        JsonValue(int value) {
            this->iValue=value;
        }
        JsonValue(std::string value) {
            this->sValue=value;
        }
        JsonValue(bool value) {
            this->bValue=value;
        }
        JsonValue(nets::JsonValue::JsonValueObj obj) {
            this->newObj=obj;
        }
//        JsonValue(nets::JsonValue &value) {
//            this->&oValue=value;
//        }
//        std::string ToString() {
//
//        }
//        ValueByName
//        JsonValue(std::string name,double value) {
//            this->dValue=value;
//            this->name=name;
//        }
//        JsonValue(std::string name,int value) {
//            this->iValue=value;
//            this->name=name;
//        }
//        JsonValue(std::string name,std::string value) {
//            this->sValue=value;
//            this->name=name;
//        }
//        JsonValue(std::string name,bool value) {
//            this->bValue=value;
//            this->name=name;
//        }
    private:
//        std::string name;
        double dValue;
        int iValue;
        std::string sValue;
        bool bValue;
        class JsonValueObj {
            double dValueObj;
            int iValueObj;
            std::string sValueObj;
            bool bValueObj;
        };
        JsonValueObj newObj;
//        JsonValue *oValue;
    };
    class View {
        std::experimental::optional <JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
