//
//  Edge.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 05.02.2021.
//

#ifndef Edge_hpp
#define Edge_hpp

#include "../../GraphLabel/GraphLabel.hpp"
#include "../../Point/Point V1/Point.hpp"
#include "../Edge V2/EdgeV2.hpp"

#include <stdio.h>
#include <utility>

typedef struct edge {
    int numberEdge;
    std::pair<point_t, point_t> points;
    std::pair<int, int> numberVertices;
    GraphLabels label;
    edge() = delete;
    edge(int number, point_t p1, point_t p2, int numberVertex1, int numberVertex2):
                                            numberEdge(number),
                                            points(std::make_pair(p1, p2)),
                                            numberVertices(std::make_pair(numberVertex1, numberVertex2)),
                                            label(GraphLabels::notvisited) { }
    
    bool isNotvisited() {
        return label == GraphLabels::notvisited;
    }
    
    bool isVisited() {
        return label == GraphLabels::visited;
    }
    
    bool isInskeleton() {
        return label == GraphLabels::inskeleton;
    }
    
    edge_v2_t adaptToEdgeV2() {
        edge_v2_t tmpEdge{numberEdge, numberVertices.first, numberVertices.second};
        return tmpEdge;
    }
    
    void swipeVertices() {
        auto tmp = numberVertices.first;
        numberVertices.first = numberVertices.second;
        numberVertices.second = tmp;
        
        auto tmpp = points.first;
        points.first = points.second;
        points.second = tmpp;
    }
} edge_t;

struct cmp {
    bool operator() (const edge_t &a, const edge_t &b) {
        return a.numberVertices.first < b.numberVertices.first || a.numberVertices.second < b.numberVertices.second;
    }
};



#endif /* Edge_hpp */
