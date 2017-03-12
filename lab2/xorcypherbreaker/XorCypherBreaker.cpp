//
// Created by patrycja on 11.03.17.
//
using namespace std;
#include "XorCypherBreaker.h"
#include <algorithm>
#include <sstream>
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                            int key_length,
                            const std::vector<std::string> &dictionary){
    string word="";
    string key="";
    int counter=1;
    int letter;
    int decryptedLetter;
    for(int firstLetter=97;firstLetter<123;firstLetter++) {
        for(int secondLetter=97;secondLetter<123;secondLetter++) {
            for(int thirdLetter=97;thirdLetter<123;thirdLetter++) {
                for (char i : cryptogram) {
                    //counter%3
                    if (counter%3==1)
                        letter=firstLetter;
                    else if (counter%3==2)
                        letter=secondLetter;
                    else
                        letter=thirdLetter;
                    decryptedLetter=letter^i;
                    if (decryptedLetter<65 or (decryptedLetter>90 and decryptedLetter<97) or decryptedLetter>122) {
                        if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end()) {
                            ostringstream stringLetter;
                            stringLetter << firstLetter;
                            string str = stringLetter.str();
                            key = key + stringLetter;
//                            stringLetter << secondLetter;
//                            key+=stringLetter;
//                            stringLetter << thirdLetter;
//                            key+=stringLetter;
                            return key;
                        }
                        word="";
                    }
                    else {
                        ostringstream ss;
                        ss << decryptedLetter;
                        string str = ss.str();
                        word = word + str;
                    }
                    counter+=1;
                }
            }
        }
    }
}
