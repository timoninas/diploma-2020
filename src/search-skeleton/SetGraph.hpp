#ifndef SetGraph_hpp
#define SetGraph_hpp

//#include "IGraph.hpp"
#include "Structs.hpp"

class SetGraph: public IGraph {
public:
    SetGraph(): graph(), vertices() { }
    
    SetGraph(const IGraph&);
    
    virtual ~SetGraph() {}
    
    int VerticesCount() const override;
    
    void AddVertex(double x, double y) override;
    
    void printVertices();
    
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector< std::unordered_set< int > > graph;
    std::vector< vertex_t > vertices;
};

#endif /* SetGraph_hpp */
