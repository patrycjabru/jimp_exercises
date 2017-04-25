//
// Created by bodzbarb on 04.04.17.
//

#include "Point.h"

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include "Point.h"

using namespace std;

int main(void){
//wywołuje konstruktor domyślny
    Point p;
    Point p2 ();
    Point p3 {}; //brace initilizer preferowany
//wywołuje konstruktor parametryczny
    Point p4 (12,34);
    Point p5 {30, 20};

    const Point *ptr_p = new Point(3,4);

    p2.ToString(&cout);
    cout <<  ptr_p->Distance(p2) << endl;

    delete ptr_p;

//parametry przekazywane do make_unique tworzące
//wskaznik unique_ptr przyjmują argumety konstruktora parametrycznego
//stąd możliwe są dwa wywowłania:
    auto ptr_p2 = make_unique<Point>();
    auto ptr_p3 = make_unique<Point>(-15,90);

    stringstream ss;
    ptr_p2.ToString(&ss);
    ss << " i ";
    ptr_p3.ToString(&ss);
    cout << "Odległość między punktami " << ss.str() << " wynosi " << ptr_p2->Distance(*ptr_p3) << endl;
    cout << "Zostanie wywołany destruktor punktów ptr_p2 i ptr_p3?" << endl;


    //ronica miedzy emplace_back a push_back:
    vector<Point> vp;
    //push_back kopiuje przekazany punkt na koniec wektora
    vp.push_back(Point {9,8});
    //natomiast emplace_back tworzy obiekt na koncu wektora
    //argumenty przekazane do funkcji odpowiadają konstruktorowi parametrycznemu
    vp.emplace_back(5, -5);
    //wiec mozna tez wywołać:
    vp.emplace_back();
}