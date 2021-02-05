#include "SetGraph.hpp"

SetGraph::SetGraph(const IGraph& sendedGraph) {
    graph.resize(sendedGraph.VerticesCount());
    for (int i = 0; i < sendedGraph.VerticesCount(); i++) {
        for (auto child: sendedGraph.GetNextVertices(i)) {
            graph[i].insert(child);
        }
    }
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

void SetGraph::AddVertex(double x, double y) {
    vertex_t v{x, y, int(vertices.size())};
    vertices.push_back(v);
}

void SetGraph::PrintVertices() {
    for (auto item: vertices) {
        std::cout << "\nVertex:" << std::endl;
        std::cout << item.numberVertex << " : (" << item.point.x << "," << item.point.y << ")" << std::endl;
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from < vertices.size());
    assert(to < vertices.size());
    assert(from >= 0);
    assert(to >= 0);
    point_t p1 = vertices[from].point;
    point_t p2 = vertices[to].point;
    edge_t e1{p1, p2, from, to};
    edges.insert(e1);
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    
    return result;
}

std::set<edge_t, cmpAngle> SetGraph::GetNextEdges(int vertex) const {
    std::set<edge_t, cmpAngle> result;
    
    for (auto item: edges) {
        if (item.numberVertices.first == vertex || item.numberVertices.second == vertex) {
            if (item.numberVertices.first != vertex) {
                std::swap(item.numberVertices.first, item.numberVertices.second);
                std::swap(item.points.first, item.points.second);
            }
            
            result.insert(item);
        }
    }
    
    std::cout << "\nEdges for vertex: " << vertex << std::endl;
    
    for (auto item: result) {
        std::cout << "" << item.numberVertices.first << "->" << item.numberVertices.second << " : (" << item.points.first.x << "," << item.points.first.y << ") -> (" << item.points.second.x << "," << item.points.second.y << ")" << std::endl;
    }
    
    std::cout << std::endl;
    
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    
    for(size_t i = 0; i < graph.size(); i++) {
        for (auto child: graph[i]) {
            if (child == vertex) {
                result.push_back(i);
                break;
            }
        }
    }
    
    return result;
}
