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
        std::unordered_map<std::string,std::string> map;
    public:
        View(std::pair<std::string, std::unordered_map<std::string, std::string>> input) {
            this->text=input.first;
            this->map=input.second;
        }
        std::string Render(const std::unordered_map<std::string, std::string> &model) const {
            std::string outputStr=this->text;
            //std::regex pattern {"{{.*}}"};
            //for( const auto& n : u ) {
            //    std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
//            for (auto &n : model) {
//                std::regex e = n.first;
//                std::regex_replace();
            unsigned long int posBeg=0;
            unsigned long int posEnd=0;
            char prev;
            bool check=0;
            std::string expression="";
            for (unsigned int i=1;i<outputStr.length();i++) {
                prev=outputStr[i-1];
                if (outputStr[i]=='{' and prev=='{')
                    posBeg=i+1;
                if (outputStr[i]=='}' and prev=='}') {
                    posEnd = i - 2;
                    check = 1;
                }
                if (check==1) {
                    for (unsigned long int j = posBeg; j < posEnd; j++) {
                        expression += outputStr[j];
                        check=0;
                    }
                    for (auto &n : model) {
                        if (n.first == expression) {
                            //str.erase(0, str.length());
                            expression=n.second;
//                            this->text.erase(posBeg,posEnd-posBeg+1);
//                            this->text.insert(posBeg,expression);
                            outputStr.replace(posBeg,posEnd,expression);
                            break;
                        }
                    }
                }
            }
            return outputStr;
        }
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
