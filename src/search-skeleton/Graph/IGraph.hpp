#ifndef IGraph_hpp
#define IGraph_hpp

#include "../Helpers/Stream/Stream.hpp"
#include "../Helpers/Libraries/Libraries.hpp"

#include "AngleOperations.hpp"
#include "../Model/Edge/Edge V1/Edge.hpp"
#include "../Model/Edge/Edge V2/EdgeV2.hpp"
#include "../Model/Vertex/Vertex V1/Vertex.hpp"
#include "../Model/Vertex/Vertex V2/VertexV2.hpp"

struct IGraph {
    virtual ~IGraph() {}
    
    virtual void AddVertex(double x, double y) = 0;
    
    virtual void AddEdge(int from, int to) = 0;
    
    virtual const vertex_v2_t& GetVertex(int at) = 0;
    
    virtual const edge_t& GetEdge(int at) = 0;
    
    virtual int VerticesCount() const = 0;
    
    virtual void PrintVertices() const = 0;
    
    virtual void SearchSkeleton(int inputVertex, int outputVertex) = 0;
    
    virtual void SearchSkeletonV2(const int inputVertex, const int outputVertex) = 0;
    
    virtual std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const = 0;
    
    virtual std::shared_ptr<std::deque<int>> LeftTraversalWithInitialization(const int& currentVertexNumber, const int& stopVertexNumber) = 0;
    
    virtual int LeftTraversalWithInitializationV2(const int& submittedVertex, const int& inputVertex, const int& outputVertex) = 0;
    
    virtual std::shared_ptr<std::deque<int>> LeftTraversalBuildingSkeleton(const int& currentVertexNumber) = 0;
    
    virtual void visitInnerEdges(const int& repeatedVertex, const int& numberEdge) = 0;
    
    virtual void MarkSkeletonVerteciesAndEdges(std::shared_ptr<std::deque<int>> needToMarkDeque) = 0;
};

#endif /* IGraph_hpp */
