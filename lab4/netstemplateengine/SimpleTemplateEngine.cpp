//
// Created by patrycja on 22.03.17.
//

#include "SimpleTemplateEngine.h"
using namespace nets;
View::View(std::string text) {
    this->text=text;
}
std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::string outputStr=this->text;
    unsigned long int posBeg=0;
    unsigned long int posEnd=0;
    char prev;
    char next;
    bool check=0;
    bool bracketSpotted=0;
    std::string expression="";
    std::string outputExpression="";
    for (unsigned long int i=1;i<outputStr.length();i++) {
        prev=outputStr[i-1];
        if (i+1<outputStr.length())
            next=outputStr[i+1];
        else
            next='a';
        if (outputStr[i]=='{' and prev=='{' and next!='{')
            posBeg=i-1;
        if (outputStr[i]=='}' and prev=='}') {
            posEnd = i;
            check = 1;
        }
        if (check==1) {
            expression="";
            outputExpression="";
            for (unsigned long int j = posBeg+2; j <= posEnd-2; j++) {
                expression += outputStr[j];
                check=0;
            }
            for (int i=0; i<expression.length();i++) {
                if (expression[i]=='}' or expression[i]=='{') {
                    bracketSpotted=1;
                    break;
                }
            }
            if (bracketSpotted==0) {
                for (auto &n : model) {
                    if (n.first == expression) {
                        outputExpression = n.second;
                        break;
                    }
                }

                outputStr.erase(posBeg, posEnd - posBeg + 1);
                outputStr.insert(posBeg, outputExpression);
                i = posBeg+outputExpression.length();
            }
            bracketSpotted=0;
        }
    }
    return outputStr;
}