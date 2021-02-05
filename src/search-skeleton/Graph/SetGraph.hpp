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
    
    void PrintVertices();
    
    void AddEdge(int from, int to) override;
    
    std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const;
    
private:
    std::vector< std::unordered_set< int > > graph;
    std::vector< vertex_t > vertices;
    std::set< edge_t, cmp > edges;
};

#endif /* SetGraph_hpp */
