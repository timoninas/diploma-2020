#ifndef IGraph_hpp
#define IGraph_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_set>
#include <utility>
#include <set>
#include <iostream>
#include <stack>

#include "AngleOperations.hpp"
#include "../Model/Edge/Edge.hpp"
#include "../Model/Vertex/Vertex.hpp"

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddVertex(double x, double y) = 0;
    
    virtual void AddEdge(int from, int to) = 0;
    
    virtual const vertex_t& GetVertex(int at) = 0;
    
    virtual const edge_t& GetEdge(int at) = 0;
    
    virtual int VerticesCount() const = 0;
    
    virtual void PrintVertices() const = 0;
    
    virtual void SearchSkeleton(int inputVertex, int outputVertex) = 0;
    
    virtual std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const = 0;
    
    virtual std::shared_ptr<std::deque<vertex_t>> LeftTraversal(const int& currentVertexNumber, const int& stopVertexNumber) = 0;
    
    virtual void visitInnerEdges(const int& repeatedVertex, const int& numberEdge) = 0;
};

#endif /* IGraph_hpp */
