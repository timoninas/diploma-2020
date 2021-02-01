//
//  Structs.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 01.02.2021.
//

#ifndef Structs_hpp
#define Structs_hpp

#include "IGraph.hpp"

double angleBetweenVectors(double x1, double y1, double x2, double y2);
double angleQuadrant(double x1, double y1, double x2, double y2);

enum GraphLabels { notvisited = 0, visited = 1, inskeleton = 2 };

typedef struct point {
    double x;
    double y;
    point() = default;
    point(double x, double y): x(x), y(y) { }
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

typedef struct edge {
    point_t point1;
    point_t point2;
    double angle;
    GraphLabels label;
    edge() = default;
    edge(point_t p1, point_t p2): point1(p1), point2(p2), label(GraphLabels::notvisited) {
        angle = angleQuadrant(p1.x, p1.y, p2.x, p2.y);
    }
} edge_t;

typedef struct vertex {
    point_t point;
    GraphLabels label;
    std::vector<edge> edges;
    
    vertex(): point({0, 0}), label(GraphLabels::notvisited), edges(0) { }
    vertex(double x, double y): point({x, y}), label(GraphLabels::notvisited), edges(0) { }
    
} vertex_t;

double angleBetweenVectors(vector_t p1, vector_t p2);
double angleQuadrant(point_t p1, point_t p2);

#endif /* Structs_hpp */
