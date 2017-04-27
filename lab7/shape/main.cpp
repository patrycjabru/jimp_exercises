//
// Created by patrycja on 15.04.17.
//
#include <Shape.h>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <iostream>

int main() {
    Triangle trojkat;
    trojkat.Draw();
    Square kwadrat;
    kwadrat.Draw();
    Circle kolo;
    kolo.Draw();
    std::vector<Shape*> v;
    std::srand(std::time(0));
    for (int i=0;i<20;i++) {
        int a=std::rand()%3;
        if (a==0) {
            Triangle *t = new Triangle();
            v.emplace_back(t);
        }
        if (a==1) {
            Square *s = new Square();
            v.emplace_back(s);
        }
        if (a==2) {
            Circle *c = new Circle();
            v.emplace_back(c);
        }
    }
    std::cout << std::endl;
    for (auto i:v)
        i->Draw();
    for (auto i:v)
        delete(i);
    v.clear();
    return 0;
}
