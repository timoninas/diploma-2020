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
#include "../Model/Edge/Edge V1/Edge.hpp"
#include "../Model/Edge/Edge V2/EdgeV2.hpp"
#include "../Model/Vertex/Vertex V1/Vertex.hpp"
#include "../Model/Vertex/Vertex V2/VertexV2.hpp"

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddVertex(double x, double y) = 0;
    
    virtual void AddEdge(int from, int to) = 0;
    
    virtual const vertex_t& GetVertex(int at) = 0;
    
    virtual const edge_t& GetEdge(int at) = 0;
    
    virtual int VerticesCount() const = 0;
    
    virtual void PrintVertices() const = 0;
    
    virtual void SearchSkeleton(int inputVertex, int outputVertex) = 0;
    
    virtual void SearchSkeletonV2(int inputVertex, int outputVertex) = 0;
    
    virtual std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const = 0;
    
    virtual std::shared_ptr<std::deque<int>> LeftTraversalWithInitialization(const int& currentVertexNumber, const int& stopVertexNumber) = 0;
    
    virtual std::shared_ptr<std::deque<int>> LeftTraversalBuildingSkeleton(const int& currentVertexNumber) = 0;
    
    virtual void visitInnerEdges(const int& repeatedVertex, const int& numberEdge) = 0;
    
    virtual void MarkSkeletonVerteciesAndEdges(std::shared_ptr<std::deque<int>> needToMarkDeque) = 0;
};

#endif /* IGraph_hpp */
