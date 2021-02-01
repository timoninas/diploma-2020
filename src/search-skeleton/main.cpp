#include <iostream>

typedef struct point {
    double x;
    double y;
} point_t;

typedef struct vector {
    double x;
    double y;
    
    vector(point_t p1, point_t p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
    
    vector(double x1, double y1, double x2, double y2) {
        x = x2 - x1;
        y = y2 - y1;
    }
    
} vector_t;

typedef struct vertex {
    point_t point;
    double angle;
} vertex_t;

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
    
    if (p2.y < p1.y) {
        angle = 360 - angle;
    }
    
    std::cout << angle << std::endl;
    return angle;
}

// Определение углов разным квадрантам
// Тк сейчас все значения с положительным знаком
int main(int argc, const char * argv[]) {
    vector_t v1{0, 0, 1, 0};
    vector_t v2{2, 2, 3, 4};
    angleQuadrant({2, 2}, {4, 0});
//    std::cout << angleBetweenVectors(v1, v2) * 180 / 3.14 << std::endl;
//    std::cout << angle(1, 0, -1, 1) * 180 / 3.14 << std::endl;
    return 0;
}
