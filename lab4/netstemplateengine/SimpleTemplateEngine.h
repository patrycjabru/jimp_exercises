//
// Created by patrycja on 22.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
namespace nets {
    class View {
    private:
        std::string text;
//        std::unordered_map<std::string,std::string> map;
    public:
//        View(std::pair<std::string, std::unordered_map<std::string, std::string>> input) {
//            this->text=input.first;
//            this->map=input.second;
//        }
        View(std::string text) {
            this->text=text;
        }
        std::string Render(const std::unordered_map<std::string, std::string> &model) const {
            std::string outputStr=this->text;
            //std::regex pattern {"{{.*}}"};
            //for( const auto& n : u ) {
            //    std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
//            for (auto &n : model) {
//                std::regex e = n.first;
//                std::regex_replace();
//            return this->text;
            std::cout << "aaa" << outputStr;
            unsigned long int posBeg=0;
            unsigned long int posEnd=0;
            char prev;
            char next;
            bool check=0;
//            bool bracketSpotted=0;
            std::string expression="";
            std::string outputExpression="";
            for (unsigned int i=1;i<outputStr.length();i++) {
                prev=outputStr[i-1];
                if (i+1<outputStr.length())
                    next=outputStr[i+1];
                else
                    next='a';
                if (outputStr[i]=='{' and prev=='{' and next!='{')
                    posBeg=i-1;
//                if (posBeg>posEnd and outputStr[i]=='}')
//                    bracketSpotted=1;
                if (outputStr[i]=='}' and prev=='}' and next!='}') {
                    posEnd = i;
//                    if (bracketSpotted==0)
                        check = 1;
                }
                if (check==1) {
                    expression="";
                    outputExpression="";
                    for (unsigned long int j = posBeg+2; j <= posEnd-2; j++) {
                        expression += outputStr[j];
                        check=0;
                    }
                    for (auto &n : model) {
                        if (n.first == expression) {
                            //str.erase(0, str.length());
                            expression=n.second;
//                            outputStr.replace(posBeg,posEnd,expression);
                            break;
                        }
                    }
                    outputStr.erase(posBeg,posEnd-posBeg+1);
                    outputStr.insert(posBeg,expression);
//                    bracketSpotted=0;
                    i=posBeg;
                }
            }
            return outputStr;
        }
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
