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
    edge_t e1{int(edges.size()), p1, p2, from, to};
    edges.push_back(e1);
}

const vertex_t& SetGraph::GetVertex(int at) {
    assert(at >= 0);
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
    
    return result;
}

void SetGraph::SearchSkeleton(int inputVertex, int outputVertex) {
    PrintVertices();
    
    auto edges = GetNextEdges(inputVertex);
    auto initialStartVertex = inputVertex;
    auto currentVertex = inputVertex;
    vertices[inputVertex].label = GraphLabels::visited;
    
    for (auto iter = edges.cbegin(); iter != edges.cend(); iter++) {
        auto currentEdge = (*iter);
        if (currentEdge.label != GraphLabels::notvisited) continue;
        
        auto nextVertex = GetVertex(currentEdge.numberVertices.second);
        auto resultTraversal = LeftTraversal(currentVertex, outputVertex);
        
        if (resultTraversal->empty()) {
            currentVertex = initialStartVertex;
        } else {
            currentVertex = resultTraversal->top().numberVertex;
        }
        
        if (currentVertex == inputVertex) {
            // Если встретился тупик, то ничего не делаем
            // TODO: Нужна проверка на цикл. Если он встретился,
            // Тогда ребра между циклом пометить посещенными
            std::cout << "FEFE\n";
        } else if (currentVertex == outputVertex) {
            // Если дошли до выходной вершины, то выходим из цикла
            std::cout << "KEKE\n";
            break;
        } else {
            // Сюда не должны зайти
            assert(1 < 0);
        }
    }
}

std::shared_ptr<std::stack<vertex_t>> SetGraph::LeftTraversal(const int& currentVertexNumber, const int& stopVertexNumber) {
    
    std::shared_ptr< std::stack<vertex_t> >vertexStack( new std::stack<vertex_t>() );
    vertexStack->push(GetVertex(currentVertexNumber));
    
    while(!vertexStack->empty()) {
        auto popedVertex = vertexStack->top();
        std::cout << popedVertex.point.x << " " << popedVertex.point.y << " " << popedVertex.label << std::endl;
        
        auto nextEdges = GetNextEdges(popedVertex.numberVertex);
        bool isFinded = false;
        
        for (auto iter = nextEdges.cbegin(); iter != nextEdges.cend(); iter++) {
            
            auto iteratedEdge = (*iter);
            
            if (iteratedEdge.isNotvisited()) {
                edges[iteratedEdge.numberEdge].label = GraphLabels::visited;
                
//                auto find = edges.
                
                auto tmpVertex = GetVertex(iteratedEdge.numberVertices.second);
                
                if (tmpVertex.isNotvisited()) {
                    vertices[tmpVertex.numberVertex].label = GraphLabels::visited;
                    tmpVertex.label = GraphLabels::visited;
                    vertexStack->push(tmpVertex);
                    isFinded = true;
                    break;
                }
            }
            
            edges[iteratedEdge.numberEdge].label = GraphLabels::visited;
        }
        
        if (isFinded) {
            auto poped = vertexStack->top();
            if (poped.numberVertex == stopVertexNumber) {
                std::cout << "STACK:" << std::endl;
                return vertexStack;
            }
        } else {
            vertexStack->pop();
        }
    }
    
    return vertexStack;
}
