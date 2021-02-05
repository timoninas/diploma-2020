#ifndef Vertex_hpp
#define Vertex_hpp

#include "../Point/Point.hpp"
#include "../GraphLabel/GraphLabel.hpp"

#include <stdio.h>

typedef struct vertex {
    point_t point;
    int numberVertex;
    GraphLabels label;
    
    vertex() = default;
    vertex(double x, double y, int numberVertex): point({x, y}), numberVertex(numberVertex), label(GraphLabels::notvisited) { }
    
} vertex_t;

#endif /* Vertex_hpp */
