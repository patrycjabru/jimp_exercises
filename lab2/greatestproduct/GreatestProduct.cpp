//
// Created by patrycja on 11.03.17.
//

#include "GreatestProduct.h"
int GreatestProduct(const std::vector<int> &numbers, int k)
{
    int numberOnePos=0;
    int numberTwoPos=0;
    int multiplicationPos=0;
    int numberOneNeg=0;
    int numberTwoNeg=0;
    int multiplicationNeg=0;
    for (int number : numbers) {
        if (number>=0) {
            if (numberOnePos < numberTwoPos) {
                if (number > numberOnePos)
                    numberOnePos = number;
            }
            else {
                if (number > numberTwoPos)
                    numberTwoPos = number;
            }
        }
        else {
            if (numberOneNeg < numberTwoNeg) {
                if (number < numberTwoNeg)
                    numberTwoNeg = number;
            }
            else
                if (number < numberOneNeg)
                    numberOneNeg = number;
        }
    }
    multiplicationPos=numberOnePos*numberTwoPos;
    multiplicationNeg=numberOneNeg*numberTwoNeg;
    if (multiplicationNeg>multiplicationPos)
        return multiplicationNeg;
    else
        return multiplicationPos;
}