//
// Created by patrycja on 11.03.17.
//
using namespace std;
#include "XorCypherBreaker.h"
#include <algorithm>
#include <sstream>
#include <iostream>

using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                            int key_length,
                            const std::vector<std::string> &dictionary){
    string word="";
    string key="";
    int counter=1;
    int letter;
    int decryptedLetter;
    int number=0;
    int theBiggestNumber=0;
    for(int firstLetter=97;firstLetter<123;firstLetter++) {
        for(int secondLetter=97;secondLetter<123;secondLetter++) {
            for(int thirdLetter=97;thirdLetter<123;thirdLetter++) {
                number=0;
                counter=1;
                for (char i : cryptogram) {
                    //counter%3
                    if (counter%3==1)
                        letter=firstLetter;
                    else if (counter%3==2)
                        letter=secondLetter;
                    else
                        letter=thirdLetter;
                    decryptedLetter=i^letter;
                    if (decryptedLetter<65 or (decryptedLetter>90 and decryptedLetter<97) or decryptedLetter>122) {
                        if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end()) {
                            number+=1;
                        }
                        word="";
                    }
                    else {
                        string str;
                        str = decryptedLetter;
                        word = word + str;
                    }
                    counter+=1;
                }
                if (number > theBiggestNumber) {
                    key="";
                    char stringLetter;
                    stringLetter = firstLetter;
                    key+=stringLetter;
                    stringLetter = secondLetter;
                    key+=stringLetter;
                    stringLetter = thirdLetter;
                    key+=stringLetter;
                    theBiggestNumber = number;
                }
            }
        }
    }
    return key;
}
