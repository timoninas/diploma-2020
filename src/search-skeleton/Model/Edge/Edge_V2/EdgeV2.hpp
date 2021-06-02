//
//  EdgeV2.hpp
//  search-skeleton
//
//  Created by Антон Тимонин on 05.04.2021.
//

#ifndef EdgeV2_hpp
#define EdgeV2_hpp

#include "../../GraphLabel/GraphLabel.hpp"
#include "../../Point/Point_V1/Point.hpp"

#include <stdio.h>
#include <utility>

typedef struct edge_v2 {
    int numberEdge;
    std::pair<int, int> numberVertices;
    GraphLabels label;
    edge_v2() = delete;
    edge_v2(int number, int numberVertex1, int numberVertex2):
                                            numberEdge(number),
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
    
    void swipeVertices() {
        auto tmp = numberVertices.first;
        numberVertices.first = numberVertices.second;
        numberVertices.second = tmp;
    }
} edge_v2_t;

struct cmp_v2 {
    bool operator() (const edge_v2_t &a, const edge_v2_t &b) {
        return a.numberVertices.first < b.numberVertices.first || a.numberVertices.second < b.numberVertices.second;
    }
};

#endif /* EdgeV2_hpp */
