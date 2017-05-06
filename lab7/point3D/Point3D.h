//
// Created by moje konto on 2017-04-27.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include "Point.h"

class Point3D : public Point {
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();

    double GetZ() const;
    void SetZ(double y);
    double Distance(const Point3D &other) const;

protected:
    double z_;
};


#endif //JIMP_EXERCISES_POINT3D_H
