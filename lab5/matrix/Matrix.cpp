//
// Created by patrycja on 01.04.17.
//

#include "Matrix.h"
using namespace std;
using namespace matrix;

Matrix::Matrix(string input) {
    int rows=1, cols=0;
    bool numberSpotted=false;
    bool semicolonSpotted=false;
    for (int i=0;i<input.length();i++) {
        if (input[i]==';') {
            rows += 1;
            semicolonSpotted=true;
        }
        if (semicolonSpotted==false and input[i]!=' ' and input[i]!=';' and input[i]!='[' and input[i]!= ']' and (input[i-1]==' ' or input[i-1]==';' or input[i-1]=='['))
            numberSpotted=true;
        else
            numberSpotted=false;
        if (numberSpotted)
            cols+=1;
    }
    complex<double>** arr = new complex<double>*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new complex<double>[cols];
    array=arr;
    int breakPoint=0;
    cout << "rows "<<rows << "cols "<<cols<<"\n";
    int begin=0;
    int end=0;
    bool beginSet=false;
    bool endSet=false;
    int r=0,c=0;
    for(int i=0;i<input.length();i++) {
        if (input[i]!=' ' and input[i]!=';' and input[i]!='[' and input[i]!=']') {
            if (input[i-1]==' ' or input[i-1]==';' or input[i-1]=='[') {
                begin = i;
                beginSet = true;
            }
        }
        else {
            if (input[i - 1] != ' ' or input[i - 1] != ';' or input[i - 1] != '[') {
                end = i;
                endSet = true;
            }
        }
        if (beginSet and endSet) {
            string tmp="";
            for (int k=begin;k<end;k++)
                tmp+=input[i];
            cout << tmp << "  ";
            std::istringstream is('(' + tmp + ')');
            is >> array[r][c];
            r++;
            if (r==rows) {
                r=0;
                c++;
            }
        }
    }
//    for(int i=0; i<rows; i++) {
//        for (int j=0; j<cols ;j++) {
//            string tmp="";
//            bool numberSpotted=false;
//            int begin=0;
//            int end=0;
//            for (end;end<input.length();end++) {
//                cout << input[breakPoint] << "  ";
//                if(input[breakPoint]!=' ' and input[breakPoint]!= ';' and input[breakPoint]!='[' and input[breakPoint]!=']') {
//                    tmp = tmp + input[breakPoint];
//                    numberSpotted = true;
//                }
//                if(numberSpotted==true and (input[breakPoint]==' ' or input[breakPoint]== ';' or input[breakPoint]=='[' or input[breakPoint]!=']') and input[breakPoint-1]!=' ' and input[breakPoint-1]!= ';' and input[breakPoint-1]!='[' and input[breakPoint-1]!=']')
//                    break;
//                if (input[end]!=' ' and input[end]!=';' and input[end]!='[' and input[end]!=']')
//                    tmp+=input[end];
//                else if (end>begin) {
//                    std::istringstream is('(' + tmp + ')');
//                    is >> array[i][j];
//                    begin=end;
//                    cout << tmp << "   ";
//
//                }
//            }
//            cout << input;
//            cout << tmp;
//            std::istringstream is('(' + tmp + ')');
//            is >> array[i][j];
//            cout << array[i][j];
            //konwersja string do complex
//        }
//    }
//    cout << "\n" <<array[0][1];
}