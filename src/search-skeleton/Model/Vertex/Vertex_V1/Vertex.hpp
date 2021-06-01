#ifndef Vertex_hpp
#define Vertex_hpp

#include "../../Point/Point_V1/Point.hpp"
#include "../../GraphLabel/GraphLabel.hpp"

#include <stdio.h>

typedef struct vertex {
    point_t point;
    int numberVertex;
    GraphLabels label;
    
    vertex() = default;
    vertex(double x, double y, int numberVertex): point({x, y}), numberVertex(numberVertex), label(GraphLabels::notvisited) { }
    
    vertex(point_t p, int numberVertex): point(p), numberVertex(numberVertex), label(GraphLabels::notvisited) { }

    bool isNotvisited() {
        return label == GraphLabels::notvisited;
    }
    
    bool isVisited() {
        return label == GraphLabels::visited;
    }
    
    bool isInskeleton() {
        return label == GraphLabels::inskeleton;
    }
} vertex_t;

#endif /* Vertex_hpp */
