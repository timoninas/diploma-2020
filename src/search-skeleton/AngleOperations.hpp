#ifndef Structs_hpp
#define Structs_hpp

#include "Model/Vector/Vector.hpp"
#include "Model/Edge/Edge.hpp"

#include <math.h>
#include <stdio.h>
#include <iostream>

double angleBetweenVectors(double x1, double y1, double x2, double y2);
double angleQuadrant(double x1, double y1, double x2, double y2);

double angleBetweenVectors(vector_t p1, vector_t p2);
double angleQuadrant(point_t p1, point_t p2);

struct cmpAngle {
    bool operator() (const edge_t &a, const edge_t &b) {
        auto pointA1 = a.points.first, pointA2 = a.points.second;
        auto pointB1 = b.points.first, pointB2 = b.points.second;
        auto angle1 = angleQuadrant(pointA1, pointA2);
        auto angle2 = angleQuadrant(pointB1, pointB2);
        return angle1 >= angle2;
    }
};

#endif /* Structs_hpp */
