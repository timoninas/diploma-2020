#ifndef SetGraph_hpp
#define SetGraph_hpp

#include "IGraph.hpp"

class SetGraph: public IGraph {
public:
    SetGraph(): graph(), vertices() { }
    
    SetGraph(const IGraph&);
    
    virtual ~SetGraph() {}
    
    int VerticesCount() const override;
    
    void AddVertex(double x, double y) override;
    
    void AddEdge(int from, int to) override;
    
    void PrintVertices() const override;
    
    void SearchSkeleton(int inputVertex, int outputVertex) override;
    
    void SearchSkeletonV2(int inputVertex, int outputVertex) override;
    
private:
    std::vector< std::unordered_set< int > > graph;
    std::vector< vertex_v2_t > vertices;
    std::vector< edge_t > edges;
    
    const vertex_v2_t& GetVertex(int at) override;
    
    const edge_t& GetEdge(int at) override;
    
    std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const override;
    
    std::shared_ptr<std::deque<int>> LeftTraversalWithInitialization(const int& currentVertexNumber, const int& stopVertexNumber) override;
    
    std::shared_ptr<std::deque<int>> LeftTraversalBuildingSkeleton(const int& currentVertexNumber) override;
    
    void visitInnerEdges(const int& repeatedVertex, const int& numberEdge) override;
    
    void MarkSkeletonVerteciesAndEdges(std::shared_ptr<std::deque<int>> needToMarkDeque) override;
};

#endif /* SetGraph_hpp */
