#include "AngleOperations.hpp"

// Get angle between two vectors
double angleBetweenVectors(vector_t p1, vector_t p2) {
    // (x1, y1) - vector from (0, 0) to (1, 0)
    // (x2, y2) - vector from p1 to p2
    
    double t = (p1.x * p2.x + p1.y * p2.y) / (sqrt(p1.x * p1.x + p1.y * p1.y) * sqrt(p2.x * p2.x + p2.y * p2.y));
    if (t < -1) t = -1;
    if (t > 1) t = 1;
    return acos(t);
}

double angleQuadrant(point_t p1, point_t p2) {
    vector_t initVector(0, 0, 1, 0);
    vector_t vectowBetweenTwoPoints{p1, p2};
    double angle = angleBetweenVectors(initVector, vectowBetweenTwoPoints) * 180 / 3.14;
    
    if (p2.y <= p1.y) {
        angle = 360 - angle;
    }
    return angle;
}

double angleBetweenVectors(double x1, double y1, double x2, double y2) {
    // (x1, y1) - vector from (0, 0) to (1, 0)
    // (x2, y2) - vector from p1 to p2
    
    double t = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    if (t < -1) t = -1;
    if (t > 1) t = 1;
    return acos(t);
}

double angleQuadrant(double x1, double y1, double x2, double y2) {
    double angle = angleBetweenVectors(1, 0, x2 - x1, y2 - y1) * 180 / 3.14;
    
    if (y2 <= y1) {
        angle = 360 - angle;
    }
    
    std::cout << "(" << x2 << ";"  << y2 << ") -> " << angle << std::endl;
    return angle;
}
