//
// Created by patrycja on 01.04.17.
//

#include "Matrix.h"
using namespace std;
using namespace matrix;

Matrix::Matrix(int rows,int cols) {
    complex<double>** arr = new complex<double>*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new complex<double>[cols];
    array=arr;
    for(int i=0;i<rows;i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j].real(0);
            array[i][j].imag(0);
        }
    }
    this->rows=rows;
    this->cols=cols;
}
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
//    cout << "rows "<<rows << "cols "<<cols<<"\n";
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
//            cout<<sReal;
            real=stod(sReal);
//            cout << sImaginary;
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
//    for (int i=0;i<3;i++) {
//        for (int j=0;j<3;j++)
//            cout << "\n" <<array[j][i] << " ";
//    cout << "\n";
//    }


}
string Matrix::print() {
    string str="";
    str+="\n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            str+=to_string(array[i][j].real());
            if (array[i][j].imag()!=0) {
                str+=" + "+to_string(array[i][j].imag())+"i";
                str+="\t\t";
            }
            else
                str+="\t\t\t\t\t";
        }
        str+="\n";
    }
    return str;
}
Matrix Matrix::add(Matrix m2) {
    if (this->cols!=m2.cols or this->rows!=m2.rows) {
        cout << "Nie mozna dodac macierzy - niepasujace wymiary.";
        Matrix m(0,0);
        return m;
    }
    Matrix output(rows,cols);
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            output.array[i][j]=array[i][j]+m2.array[i][j];
        }
    }
    return output;
}
Matrix Matrix::sub(Matrix m2) {
    if (this->cols!=m2.cols or this->rows!=m2.rows) {
        cout << "Nie mozna odjac macierzy - niepasujace wymiary.";
        Matrix m(0,0);
        return m;
    }
    Matrix output(rows,cols);
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            output.array[i][j]=array[i][j]-m2.array[i][j];
        }
    }
    return output;
}
Matrix Matrix::mul(Matrix m2) {
    if (this->cols!=m2.rows) {
        cout << "Nie mozna pomnozyc macierzy - niepasujace wymiary.";
        Matrix m(0,0);
        return m;
    }
    Matrix w(this->rows,m2.cols);
    for (int r=0;r<this->rows;r++) {
        for (int c = 0; c < m2.cols; c++) {
            for (int i = 0; i < this->cols; i++) {
                w.array[r][c] += this->array[r][i] * m2.array[i][c];
            }
        }
    }
    return w;
}
complex<double> Matrix::determinant() {
    if (this->rows!=this->cols) {
        cout << "Nie mozna policzyc wyznacznika - nieodpowiednie wymiary.";
        return (0.0);
    }
    if (this->rows==1)
        return this->array[0][0];
    Matrix m(this->rows-1,this->cols-1);
    int r=0,c=0;
    for (int a=0;a<this->rows;a++) {
        for (int b=0;b<this->cols;b++) {
            if (a==i or b)
        }
    }
}
Matrix Matrix::div(Matrix m2) {
    if (this->cols!=this->rows or m2.cols!=m2.rows or this->cols!=m2.cols) {
        cout << "Nie mozna podzielic macierzy - niepasujace wymiary.";
        Matrix m(0,0);
        return m;
    }

}
