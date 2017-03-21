//
// Created by bodzbarb on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include <cmath>
#include <iostream>

//void Point::ToString(ostream *out);

class Point {
public:
    Point(double x, double y)
    {
        x_=x;
        y_=y;
    }

    double GetX() const
    {
        return x_;
    }
    double GetY() const
    {
        return y_;
    }

private:
    double x_, y_;
};

class Square {
public:
    const Point *A = new Point(0,0);
    const Point *B = new Point(2,0);
    const Point *C = new Point(0,2);
    const Point *D = new Point(2,2);

    double  Circumference()
    {
        double AB;
        double AD;
        double bok;
        AB=std::sqrt(pow((this->B->GetX()-A->GetX()),2)+pow((this->B->GetY()-A->GetY()),2));
        AD=std::sqrt(pow((this->D->GetX()-A->GetX()),2)+pow((this->D->GetY()-A->GetY()),2));
        if(AD<=AB)
            bok=AD;
        else
            bok=AB;
        return 4*bok;
    }
    double  Area()
    {
        double AB;
        double AD;
        double bok;
        AB=std::sqrt(pow((this->B->GetX()-A->GetX()),2)+pow((this->B->GetY()-A->GetY()),2));
        AD=std::sqrt(pow((this->D->GetX()-A->GetX()),2)+pow((this->D->GetY()-A->GetY()),2));
        if(AD<=AB)
            bok=AD;
        else
            bok=AB;
        return bok*bok;
    }

};

#endif //JIMP_EXERCISES_SQUARE_H
