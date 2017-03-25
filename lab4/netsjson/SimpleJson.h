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
    public:
        double dValue;
        int iValue;
        std::string sValue;
        bool bValue;
        std::vector<JsonValue> vValue;
        std::map<std::string,JsonValue> mValue;
        int whichValue=0;
        JsonValue(double value) {
            this->dValue=value;
            this->whichValue=1;
        }
        JsonValue(int value) {
            this->iValue=value;
            this->whichValue=2;
        }
        JsonValue(std::string value) {
            this->sValue=value;
            this->whichValue=3;
        }
        JsonValue(bool value) {
            this->bValue=value;
            this->whichValue=4;
        }
        JsonValue(std::vector<JsonValue> vec) {
            this->vValue = vec;
            this->whichValue=5;
        }
        JsonValue(std::map<std::string,JsonValue> map) {
            this->mValue=map;
            this->whichValue=6;
        }

        std::experimental::optional <JsonValue> ValueByName(const std::string &name) const {
            std::experimental::optional <JsonValue> exp;
            std::map<std::string,JsonValue>::const_iterator it;
            it=this->mValue.find(name);
            exp=it->second;
            return exp;
        }

        std::string ToString() const {
            std::string outputStr="";
//            std::cout << "vv: " << this->whichValue;
//            if (this->whichValue==0) {
//                outputStr="";
//                std::cout << "tutaj!";
//            }
            std::cout << "tuuu";
            if (this->whichValue==1) {
                outputStr=std::to_string(this->dValue);
//                outputStr[outputStr.length()-1]=null;
            }
            if (this->whichValue==2) {
                std::cout << " w inttt";
//                std::stringstream ss;
//                ss << this->iValue;
//                outputStr = ss.str();
//                std::cout << "aaaaaaaaaaaaaaaaaaaaaa" << outputStr;
                outputStr=std::to_string(this->iValue);
            }
            if (this->whichValue==3) {
                outputStr = "\""+this->sValue+"\"";
            }
            if (this->whichValue==4) {
//                std::cout << "w boool";
                if (this->bValue==0)
                    outputStr="false";
                else
                    outputStr="true";
            }
            if (this->whichValue==5) {
                outputStr="[";
                for(int i=0; i < this->vValue.size(); i++){
//                    outputStr+=std::to_string(this->vValue[i]);
                }
//                for (auto v : this->vValue) {
//                    outputStr+=std::to_string(v);
//                }
            }
            if (this->whichValue==6) {
                outputStr="";
            }
            return outputStr;
        }
//        std::string name;

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
