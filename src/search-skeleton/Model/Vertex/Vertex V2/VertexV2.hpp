#ifndef VertexV2_hpp
#define VertexV2_hpp

#include "../../Point/Point V1/Point.hpp"
#include "../../Edge/Edge V2/EdgeV2.hpp"
#include "../../GraphLabel/GraphLabel.hpp"

#include <stdio.h>
#include <vector>

typedef struct vertex_v2 {
    int numberVertex;
    point_t point;
    std::vector<int> numberEdges;
    GraphLabels label;
    
    vertex_v2() = default;
    vertex_v2(double x, double y, int numberVertex): point({x, y}), numberVertex(numberVertex), numberEdges(), label(GraphLabels::notvisited) { }
    
    vertex_v2(point_t p, int numberVertex): numberVertex(numberVertex), point(p), numberEdges(), label(GraphLabels::notvisited) { }

    bool isNotvisited() {
        return label == GraphLabels::notvisited;
    }
    
    bool isVisited() {
        return label == GraphLabels::visited;
    }
    
    bool isInskeleton() {
        return label == GraphLabels::inskeleton;
    }
} vertex_v2_t;

#endif /* VertexV2_hpp */
