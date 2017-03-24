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
    private:
//        std::string name;
        double dValue;
        int iValue;
        std::string sValue;
        bool bValue;
        class JsonValueObj {
        public:
            double dValueObj;
            int iValueObj;
            std::string sValueObj;
            bool bValueObj;
            std::map<std::string,JsonValue> newMap;
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
            class JsonValueObj2 {
            public:
                double dValueObj2;
                int iValueObj2;
                std::string sValueObj2;
                bool bValueObj2;
                std::map<std::string,JsonValue> newMap2;
            };
            JsonValueObj2 newObj2;
            JsonValueObj(nets::JsonValue::JsonValueObj::JsonValueObj2 obj2) {
                this->newObj2=obj2;
            }
        };
        JsonValueObj newObj;
//        JsonValue *oValue;
        std::vector<JsonValue> newVector;
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
        JsonValue(std::vector<JsonValue> vec) {
            this->newVector = vec;
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

    };
    class View {
        std::experimental::optional <JsonValue> ValueByName(const std::string &name) const {
            std::experimental::optional <JsonValue> aaa;
//            JsonValue aaa(1);
            return aaa;
        }

        std::string ToString() const {
            return "";
        }
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
