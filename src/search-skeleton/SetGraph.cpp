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

void SetGraph::printVertices() {
    for (auto item: vertices) {
        std::cout << "\n Vertex:" << std::endl;
        std::cout << item.numberVertex << " | " << item.point.x << " " << item.point.y << std::endl;
        if (item.edges.size() != 0) {
            std::cout << "Edges:" << std::endl;
        }
        for (auto item2: item.edges) {
            std::cout << item2.numberVertex << " | " << item2.point.x << " " << item2.point.y << " | " << item2.angle <<  std::endl;
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from < vertices.size());
    assert(to < vertices.size());
    assert(from >= 0);
    assert(to >= 0);
    point_t p1 = vertices[from].point;
    point_t p2 = vertices[to].point;
    edge_t e{p1, p2, to};
    vertices[from].edges.insert(e);
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    
    for (auto val: graph[vertex]) {
        result.push_back(val);
    }
    
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
