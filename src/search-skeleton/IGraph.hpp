#ifndef IGraph_hpp
#define IGraph_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <set>
#include <iostream>

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddVertex(int from, double x, double y) = 0;
    
    virtual void AddEdge(int from, int to) = 0;
    
    virtual int VerticesCount() const = 0;
    
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif /* IGraph_hpp */
