//
// Created by patrycja on 22.03.17.
//
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
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
        JsonValue(std::vector<JsonValue> vec) {
            this->vValue = vec;
        }
        JsonValue(std::map<std::string,JsonValue> map) {
            this->mValue=map;
        }

        std::experimental::optional <JsonValue> ValueByName(const std::string &name) const {
            std::experimental::optional <JsonValue> exp;
            std::map<std::string,JsonValue>::const_iterator it;
            it=this->mValue.find(name);
            exp=it->second;
            return exp;
        }

        std::string ToString() const {
            return "";
        }
    private:
//        std::string name;
        double dValue;
        int iValue;
        std::string sValue;
        bool bValue;
        std::vector<JsonValue> vValue;
        std::map<std::string,JsonValue> mValue;
//            JsonValueObj(double value) {
//                this->dValueObj=value;
//            }
//            JsonValueObj(int value) {
//                this->iValueObj=value;
//            }
//            JsonValueObj(std::string value) {
//                this->sValueObj=value;
//            }
//            JsonValueObj(bool value) {
//                this->bValueObj=value;
//            }
//            JsonValueObj(std::map<std::string,JsonValue> value) {
//                this->newMap=value;
//            }

//        JsonValue *oValue;

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

    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
