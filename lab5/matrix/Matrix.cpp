//
// Created by patrycja on 01.04.17.
//
//kom

#include "Matrix.h"
using namespace std;
using namespace algebra;

std::string dtos(double x) {
    std::stringstream s;
    s << x;
    return s.str();
}
pair<size_t, size_t> Matrix::Size() {
    pair<size_t, size_t> size;
    size = make_pair(rows,cols);
    return size;
};
Matrix::Matrix() {
    array=nullptr;
    rows=0;
    cols=0;
}
Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &m):data(m) {
    rows=data.size();
    cols=data[0].size();
    complex<double>** arr = new complex<double>*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new complex<double>[cols];
    array=arr;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            array[i][j]=data[i][j];
        }
    }
}
Matrix::Matrix(int rows,int cols) {
    if (rows and cols) {
        complex<double> **arr = new complex<double> *[rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new complex<double>[cols];
        array = arr;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j].real(0);
                array[i][j].imag(0);
            }
        }
        this->rows=rows;
        this->cols=cols;
    }
    else {
        array = nullptr;
        this->rows=0;
        this->cols=0;
    }
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
            real=stod(sReal);
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
}
Matrix::Matrix(const Matrix &m) {
    rows=m.rows;
    cols=m.cols;
    if (rows and cols) {
        complex<double>** arr = new complex<double>*[rows];
        for(int i = 0; i < rows; i++)
            arr[i] = new complex<double>[cols];
        array=arr;
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                array[i][j]=m.array[i][j];
            }
        }
    }
}
Matrix::~Matrix() {
    if (rows and cols) {
        for (int i = 0; i < rows; i++)
            delete[] array[i];
        delete[] array;
    }
    array= nullptr;
    rows=0;
    cols=0;
}
string Matrix::Print() const {
    string str="";
    str+="[";
    for (int i=0;i<rows;i++) {
        for (int j = 0; j < cols; j++) {
            str += dtos(array[i][j].real());
            str += "i";
            str += dtos(array[i][j].imag());
            if (j!=cols-1)
                str += ", ";
        }
        if (i!=rows-1)
            str += "; ";
    }
    str+="]";
    return str;
}
Matrix Matrix::Add(Matrix m2) const {
    Matrix output(rows,cols);
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            output.array[i][j]=array[i][j]+m2.array[i][j];
        }
    }
    return output;
}
Matrix Matrix::Sub(Matrix m2) {
    if (this->cols!=m2.cols or this->rows!=m2.rows) {
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
Matrix Matrix::Mul(Matrix m2) {
    if (this->cols!=m2.rows or this->rows==0 or m2.rows==0) {
        Matrix m;
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
//complex<double> Matrix::Determinant(int i,int j) {
//    if (i>this->rows or j>this->cols) {
//        cout << "Nieodpowiednie argumenty";
//        return (0.0);
//    }
//    if (this->rows!=this->cols) {
//        cout << "Nie mozna policzyc wyznacznika - nieodpowiednie wymiary.";
//        return (0.0);
//    }
//    if (this->rows==1)
//        return this->array[0][0];
//    Matrix m(this->rows-1,this->cols-1);
//    int r=0,c=0;
//    for (int a=0;a<this->rows;a++) {
//        for (int b=0;b<this->cols;b++) {
//            if (a==i or b==j)
//                continue;
//            m.array[r][c]=this->array[a][b];
//            c++;
//            if (c==m.cols) {
//                c=0;
//                r++;
//            }
//        }
//    }
//    complex<double> tmp;
//    tmp.real((-1)^(i+j));
//    tmp.imag(0);
//    return tmp * this->array[0][j] * m.Determinant(0,0);
//}
//Matrix Matrix::Div(Matrix m2) {
//    if (this->cols!=this->rows or m2.cols!=m2.rows or this->cols!=m2.cols) {
//        cout << "Nie mozna podzielic macierzy - niepasujace wymiary.";
//        Matrix m(0,0);
//        return m;
//    }
//
//}
Matrix Matrix::Pow(int p) const {
    if(!rows or !cols)
        return Matrix();
    if(rows!=cols)
        return Matrix();
    if (p==1)
        return *this;
    if(p==0)
    {
        Matrix output(rows,cols);
        for(auto i=0;i<rows;i++)
            for(auto j=0;j<cols;j++)
                if(i==j) {
                    output.array[i][j].real(1);
                    output.array[i][j].imag(0);
                }
                else {
                    output.array[i][j].real(0);
                    output.array[i][j].imag(0);
                }
        return output;
    }
    Matrix output{*this};
    for (int i=0;i<p-1;i++) {
        output=output.Mul(*this);
    }
    return output;
}
