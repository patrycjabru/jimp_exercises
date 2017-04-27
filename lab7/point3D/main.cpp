//
// Created by moje konto on 2017-04-27.
//

#include <iostream>
#include "Point3D.h"

using namespace std;

int main() {
    Point p2d{2,4};
    Point3D p3d{1,2,3};
    // najpierw wywołany zostanie konstruktor point, a potem point3d
    // dla destruktorów odwrotna kolejność

    cout << p2d.Distance(p3d) << endl;
    // funkcja liczy dystans 2d, ponieważ jest wywołana dla punktu 2d; ignoruje trzecią wartość p3d

    cout << p3d << endl;
    // wypisze tylko pierwsze 2 wartości p3d, ponieważ operator << był stworzony dla klasy Point

    return 0;
}