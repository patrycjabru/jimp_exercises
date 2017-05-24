//
// Created by moje konto on 2017-04-27.
//

//Definicja znajduje się w pliku Point.cpp

#include <cmath>
#include <iostream>
#include "Point3D.h"

using ::std::cout;
using ::std::endl;

Point3D::Point3D():z_(0){
    cout << "Konstruktor bezparametrowy - Point3D" << endl;
}

Point3D::Point3D(double x, double y, double z) : Point(x,y) {
    cout << "Konstruktor parametrowy - Point3D" << endl;
    z_ = z;
}

Point3D::~Point3D(){
    cout << "Destruktor - Point3D";
    cout << endl;
}

double Point3D::Distance(const Point3D &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2)+pow(GetZ()-other.GetZ(),2));
}

double Point3D::GetZ() const {
    return z_;
}

void Point3D::SetZ(double z) {
    z_=z;
}