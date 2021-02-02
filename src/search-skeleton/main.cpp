#include "SetGraph.hpp"



// Определение углов разным квадрантам
// Тк сейчас все значения с положительным знаком
int main(int argc, const char * argv[]) {
    
    SetGraph graph;
    
    graph.AddVertex(18, 6);
    graph.AddVertex(18, 11);
    graph.AddVertex(17, 7);
    graph.AddVertex(22, 4);
    graph.AddVertex(21, 0);
    graph.AddVertex(24, 5);
    graph.AddVertex(20, 10);
    
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(0, 4);
    graph.AddEdge(0, 5);
    graph.AddEdge(0, 6);
    
    graph.printVertices();
    
    vector_t v1{0, 0, 1, 0};
    vector_t v2{2, 2, 3, 4};
    
//    angleQuadrant({5, 5}, {9, 5});
//    angleQuadrant({5, 5}, {9, 4});
//    angleQuadrant({5, 5}, {8, 2});
//    angleQuadrant({5, 5}, {6, 1});
//    angleQuadrant({5, 5}, {5, 1});
//    angleQuadrant({5, 5}, {2, 2});
//    angleQuadrant({5, 5}, {2, 5});
//    angleQuadrant({5, 5}, {2, 8});
//    angleQuadrant({5, 5}, {5, 8});
//    angleQuadrant({5, 5}, {8, 8});
    
//    std::cout << angleBetweenVectors(v1, v2) * 180 / 3.14 << std::endl;
//    std::cout << angle(1, 0, -1, 1) * 180 / 3.14 << std::endl;
    return 0;
}
