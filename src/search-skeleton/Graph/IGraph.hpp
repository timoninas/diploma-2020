#ifndef IGraph_hpp
#define IGraph_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <set>
#include <iostream>

#include "AngleOperations.hpp"
#include "../Model/Edge/Edge.hpp"
#include "../Model/Vertex/Vertex.hpp"

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddVertex(double x, double y) = 0;
    
    virtual void AddEdge(int from, int to) = 0;
    
    virtual int VerticesCount() const = 0;
    
    virtual void PrintVertices() const = 0;
    
    virtual void SearchSkeleton(int inputVertex, int outputVertex) = 0;
    
    virtual std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const = 0;
};

#endif /* IGraph_hpp */
