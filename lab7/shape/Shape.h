//
// Created by patrycja on 15.04.17.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H
class Shape {
public:
    virtual void Draw() = 0;
};
class Triangle:public Shape {
public:
    Triangle() = default;
    Triangle(const Triangle &t) = default;
    Triangle(Triangle &t) = default;
    void Draw() override ;
};
class Square:public Shape {
public:
    Square() = default;
    Square(const Square &s) = default;
    Square(Square &s) = default;
    void Draw() override ;
};
class Circle:public Shape {
public:
    Circle() = default;
    Circle(const Circle &c) = default;
    Circle(Circle &s) = default;
    void Draw() override ;
};
#endif //JIMP_EXERCISES_SHAPE_H
