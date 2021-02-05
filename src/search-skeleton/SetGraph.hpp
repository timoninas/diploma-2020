#ifndef SetGraph_hpp
#define SetGraph_hpp

//#include "IGraph.hpp"
#include "Structs.hpp"

struct cmpAngle {
    bool operator() (const edge_t &a, const edge_t &b) {
        auto pointA1 = a.points.first, pointA2 = a.points.second;
        auto pointB1 = b.points.first, pointB2 = b.points.second;
        auto angle1 = angleQuadrant(pointA1, pointA2);
        auto angle2 = angleQuadrant(pointB1, pointB2);
        return angle1 >= angle2;
    }
};

class SetGraph: public IGraph {
public:
    SetGraph(): graph(), vertices() { }
    
    SetGraph(const IGraph&);
    
    virtual ~SetGraph() {}
    
    int VerticesCount() const override;
    
    void AddVertex(double x, double y) override;
    
    void PrintVertices();
    
    void AddEdge(int from, int to) override;
    
    std::vector<int> GetNextVertices(int vertex) const override;
    
    std::set<edge_t, cmpAngle> GetNextEdges(int vertex) const;
    
    std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector< std::unordered_set< int > > graph;
    std::vector< vertex_t > vertices;
    std::set< edge_t, cmp > edges;
};

#endif /* SetGraph_hpp */
