//
//  Vector.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 05.02.2021.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include "Point.hpp"

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

#endif /* Vector_hpp */
