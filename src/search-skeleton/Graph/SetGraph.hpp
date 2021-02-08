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
    
    const vertex_t& GetVertex(int at) override;
    
    void PrintVertices() const override;
    
    void SearchSkeleton(int inputVertex, int outputVertex) override;
    
    std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const override;
    
    const vertex_t& LeftTraversal(vertex_t& currentVertex, vertex_t& nextVertex, edge_t& currentEdge, const int& stopVertexNumber) override;
    
private:
    std::vector< std::unordered_set< int > > graph;
    std::vector< vertex_t > vertices;
    std::set< edge_t, cmp > edges;
};

#endif /* SetGraph_hpp */
