#include "SetGraph.hpp"

SetGraph::SetGraph(const IGraph& sendedGraph) {
    graph.resize(sendedGraph.VerticesCount());
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

void SetGraph::AddVertex(double x, double y) {
    vertex_t v{x, y, int(vertices.size())};
    vertices.push_back(v);
}

void SetGraph::PrintVertices() const {
    for (auto item: vertices) {
        std::cout << "\nVertex:" << std::endl;
        std::cout << item.numberVertex << " : (" << item.point.x << "," << item.point.y << ")" << std::endl;
        GetNextEdges(item.numberVertex);
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

const vertex_t& SetGraph::GetVertex(int at) {
    assert(at > 0);
    assert(at < vertices.size());
    return vertices[at];
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
    
//    std::cout << "Edges for vertex: " << vertex << std::endl;
//
//    for (auto item: result) {
//        std::cout << "" << item.numberVertices.first << "->" << item.numberVertices.second << " : (" << item.points.first.x << "," << item.points.first.y << ") -> (" << item.points.second.x << "," << item.points.second.y << ")" << std::endl;
//    }
//    
//    std::cout << std::endl;
    
    return result;
}

void SetGraph::SearchSkeleton(int inputVertex, int outputVertex) {
    PrintVertices();
    
    auto edges = GetNextEdges(inputVertex);
    auto initialStartVertex = GetVertex(inputVertex);
    auto currentVertex = GetVertex(inputVertex);
    initialStartVertex.label = GraphLabels::visited;
    
    for (auto iter = edges.cbegin(); iter != edges.cend(); iter++) {
        auto currentEdge = (*iter);
        if (currentEdge.label != GraphLabels::notvisited) continue;
        
        auto nextVertex = GetVertex(currentEdge.numberVertices.second);
        currentVertex = LeftTraversal(initialStartVertex, nextVertex, currentEdge, outputVertex);
        
        if (currentVertex.numberVertex == inputVertex) {
            // Если встретился тупик, то ничего не делаем
            // TODO: Нужна проверка на цикл. Если он встретился,
            // Тогда ребра между циклом пометить посещенными
            std::cout << "FEFE\n";
        } else if (currentVertex.numberVertex == outputVertex) {
            // Если дошли до выходной вершины, то выходим из цикла
            std::cout << "KEKE\n";
            break;
        } else {
            // Сюда не должны зайти
            assert(1 < 0);
        }
    }
}

const vertex_t& SetGraph::LeftTraversal(vertex_t& currentVertex, vertex_t& nextVertex, edge_t& currentEdge, const int& stopVertexNumber) {
    std::cout << "LOLO" << std::endl;
    currentEdge.label = GraphLabels::visited;
    nextVertex.label = GraphLabels::visited;
    
    auto edges = GetNextEdges(nextVertex.numberVertex);
    
    for (auto iter = edges.cbegin(); iter != edges.cend(); iter++) {
        if (nextVertex.numberVertex == stopVertexNumber) {
            std::cout << "KYMA\n";
            assert(1 < 0);
        } // 23 25 25 25 24 23
        auto currentEdge = (*iter);
        auto nextNextVertex = GetVertex(currentEdge.numberVertices.second);
        std::cout << nextVertex.numberVertex << " " << nextNextVertex.numberVertex << std::endl;
        auto gettingVertex = LeftTraversal(nextVertex, nextNextVertex, currentEdge, stopVertexNumber);
        if (gettingVertex.numberVertex == currentVertex.numberVertex) {
            // Если встретился тупик, то ничего не делаем
            // TODO: Нужна проверка на цикл. Если он встретился,
            // Тогда ребра между циклом пометить посещенными
            std::cout << "FEFE\n";
            break;
        } else if (currentVertex.numberVertex == stopVertexNumber) {
            // Если дошли до выходной вершины, то выходим из цикла
            std::cout << "KEKE\n";
            break;
        } else {
            // Сюда не должны зайти
            std::cout << "MAMA\n";
        }
    }
    
    return GetVertex(currentVertex.numberVertex);
}
