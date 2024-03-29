#ifndef IGraph_hpp
#define IGraph_hpp

#include "../Helpers/Stream/Stream.hpp"
#include "../Helpers/Libraries/Libraries.hpp"

#include "../AngleOperations.hpp"
#include "../Model/Edge/Edge_V1/Edge.hpp"
#include "../Model/Edge/Edge_V2/EdgeV2.hpp"
#include "../Model/Vertex/Vertex_V1/Vertex.hpp"
#include "../Model/Vertex/Vertex_V2/VertexV2.hpp"

struct IGraph {
    virtual ~IGraph() {}
    virtual bool AddVertex(double x, double y) = 0;
    virtual bool AddVertex(point_t p) = 0;
    virtual bool AddEdge(int from, int to) = 0;
    virtual bool AddEdge(point_t p1, point_t p2) = 0;
    virtual const vertex_v2_t& GetVertex(int at) = 0;
    virtual const edge_t& GetEdge(int at, int fromVertexNumber) = 0;
    virtual const edge_t& GetEdge(int at) = 0;
    virtual int VerticesCount() const = 0;
    virtual void PrintVertices() const = 0;
    virtual void PrintEdges() const = 0;
    virtual void SearchSkeleton(int inputVertex, int outputVertex) = 0;
    virtual std::shared_ptr<std::deque<int>> SearchSkeletonV2(const int inputVertex, const int outputVertex) = 0;
    virtual std::shared_ptr<std::deque<int>> SearchSkeletonV2(const point_t inputPoint, const point_t outputPoint) = 0;
    virtual std::shared_ptr<std::deque<std::tuple<point_t, point_t, int>>> GetSkeleton() = 0;
    virtual std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const = 0;
    virtual std::shared_ptr<std::deque<int>> RightTraversal(const int& submittedVertexNumber, const int& outversalVertexNumber) = 0;
    virtual std::shared_ptr<std::deque<int>> LeftTraversalWithInitialization(const int& currentVertexNumber, const int& stopVertexNumber) = 0;
    virtual std::shared_ptr<std::deque<int>> LeftTraversalMainPartV2(const int& submittedVertexNumber) = 0;
    virtual std::shared_ptr<std::deque<int>> LeftTraversalMainPartV2(const int& submittedVertexNumber, const int& submittedEdgeNumber, const int& isSameVertexNumber) = 0;
    virtual int LeftTraversalWithInitializationV2(const int& submittedVertex, const int& inputVertex, const int& outputVertex) = 0;
    virtual std::shared_ptr<std::deque<int>> LeftTraversalBuildingSkeleton(const int& currentVertexNumber) = 0;
    virtual void visitInnerEdges(const int& repeatedVertex, const int& numberEdge) = 0;
    virtual void MarkSkeletonVerteciesAndEdges(std::shared_ptr<std::deque<int>> needToMarkDeque) = 0;
};

#endif /* IGraph_hpp */
