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
    this->rows=rows;
    this->cols=cols;
    complex<double>** arr = new complex<double>*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new complex<double>[cols];
    array=arr;
    cout << "rows "<<rows << "cols "<<cols<<"\n";
    int begin=0;
    int end=0;
    bool beginSet=false;
    bool endSet=false;
    int r=0,c=0;
    for(int i=1;i<input.length();i++) {
        if (input[i]!=' ' and input[i]!=';' and input[i]!='[' and input[i]!=']') {
            if (input[i-1]==' ' or input[i-1]==';' or input[i-1]=='[') {
                begin = i;
                beginSet = true;
            }
        }
        else if (beginSet==true){
            if (input[i - 1] != ' ' or input[i - 1] != ';' or input[i - 1] != '[') {
                end = i;
                endSet = true;
            }
        }
        if (beginSet and endSet) {
            string tmp="";
            for (int k=begin;k<end;k++) {
                tmp += input[k];
            }
            bool separatorSpotted=false;
            double real=0;
            string sReal="";
            double imaginary=0;
            string sImaginary="";
            for (int z=0;z<tmp.length();z++) {
                if (tmp[z]=='i')
                    separatorSpotted=true;
                if (separatorSpotted==false)
                    sReal+=tmp[z];
                else if (tmp[z]!='i')
                    sImaginary+=tmp[z];
            }
            cout<<sReal;
            real=stod(sReal);
            cout << sImaginary;
            if (separatorSpotted)
                imaginary=stod(sImaginary);
            (array[r][c]).real(real);
            (array[r][c]).imag(imaginary);
            r++;
            if (r==rows) {
                r=0;
                c++;
            }
            beginSet=false;
            endSet=false;
        }
    }
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++)
            cout << "\n" <<array[j][i] << " ";
    cout << "\n";
    }


}
string Matrix::print() {

}