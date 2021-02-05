//
//  Edge.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 05.02.2021.
//

#ifndef Edge_hpp
#define Edge_hpp

#include "../GraphLabel/GraphLabel.hpp"
#include "../Point/Point.hpp"

#include <stdio.h>
#include <utility>

typedef struct edge {
    std::pair<point_t, point_t> points;
    std::pair<int, int> numberVertices;
    GraphLabels label;
    edge() = delete;
    edge(point_t p1, point_t p2, int numberVertex1, int numberVertex2):
                                            points(std::make_pair(p1, p2)),
                                            numberVertices(std::make_pair(numberVertex1, numberVertex2)),
                                            label(GraphLabels::notvisited) { }
} edge_t;

struct cmp {
    bool operator() (const edge_t &a, const edge_t &b) {
        return a.numberVertices.first < b.numberVertices.first || a.numberVertices.second < b.numberVertices.second;
    }
};



#endif /* Edge_hpp */
