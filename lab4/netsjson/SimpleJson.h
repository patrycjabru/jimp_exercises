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
            dValue=value;
            whichValue=1;
        }
        JsonValue(int value) {
            iValue=value;
            whichValue=2;
        }
        JsonValue(std::string value) {
            sValue=value;
            whichValue=3;
        }
        JsonValue(bool value) {
            bValue=value;
            whichValue=4;
        }
        JsonValue(std::vector<JsonValue> vec) {
            vValue = vec;
            whichValue=5;
        }
        JsonValue(std::map<std::string,JsonValue> map) {
            mValue=map;
            whichValue=6;
        }
        std::experimental::optional <JsonValue> ValueByName(const std::string &name) const {
            std::experimental::optional <JsonValue> exp;
            std::map<std::string,JsonValue>::const_iterator it;
            auto search = mValue.find(name);
            if(search != mValue.end()) {
                it = mValue.find(name);
                exp = it->second;
            }
            return exp;
        }
        std::string ToString() const {
//            std::string outputStr="";
//            if (whichValue==1) {
//                std::string temp=std::to_string(dValue);
//                for (int i=0;i<temp.length()-4;i++) {
//                    outputStr+=temp[i];
//                }
//                return outputStr;
//            }
//            if (whichValue==2) {
//                outputStr=std::to_string(iValue);
//                return outputStr;
//            }
//            if (whichValue==3) {
//                outputStr = "\""+sValue+"\"";
//                return outputStr;
//            }
//            if (whichValue==4) {
//                if (bValue==0)
//                    outputStr="false";
//                else
//                    outputStr="true";
//                return outputStr;
//            }
//            if (whichValue==5) {
//                outputStr="[";
//                for(int i=0; i < vValue.size(); i++){
//                    outputStr+=((vValue[i]).ToString());
//                    if (i<vValue.size()-1)
//                        outputStr+=", ";
//                }
//                outputStr+="]";
//                return outputStr;
//            }
//            if (whichValue==6) {
//                outputStr="";
//                return outputStr;
//            }
            return "";
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
