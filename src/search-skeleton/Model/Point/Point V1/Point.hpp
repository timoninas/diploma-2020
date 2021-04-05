//
//  Point.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 05.02.2021.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

typedef struct point {
    double x;
    double y;
    point() = delete;
    point(double x, double y): x(x), y(y) { }
} point_t;

#endif /* Point_hpp */
