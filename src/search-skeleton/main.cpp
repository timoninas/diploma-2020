#include "SetGraph.hpp"



// Определение углов разным квадрантам
// Тк сейчас все значения с положительным знаком
int main(int argc, const char * argv[]) {
    
    SetGraph graph;
    
    graph.AddVertex(0, 0); // 0
    graph.AddVertex(2, -2); // 1
    graph.AddVertex(5, -1); // 2
    graph.AddVertex(6, 1); // 3
    graph.AddVertex(7, -3); // 4
    graph.AddVertex(6, -6); // 5
    graph.AddVertex(7, -8); // 6
    graph.AddVertex(3, -9); // 7
    graph.AddVertex(1, -7); // 8
    graph.AddVertex(4, -11); // 9
    graph.AddVertex(10, -4); // 10
    graph.AddVertex(11, -1); // 11
    graph.AddVertex(13, -5); // 12
    graph.AddVertex(16, -7); // 13
    graph.AddVertex(14, -10); // 14
    graph.AddVertex(15, -14); // 15
    graph.AddVertex(9, -12); // 16
    graph.AddVertex(12, -9); // 17
    
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(2, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 6);
    graph.AddEdge(5, 7);
    graph.AddEdge(7, 8);
    graph.AddEdge(7, 9);
    graph.AddEdge(4, 10);
    graph.AddEdge(10, 11);
    graph.AddEdge(10, 12);
    graph.AddEdge(12, 13);
    graph.AddEdge(13, 14);
    graph.AddEdge(14, 17);
    graph.AddEdge(14, 15);
    graph.AddEdge(14, 15);
    graph.AddEdge(16, 17);
    graph.AddEdge(16, 15);
    
    graph.PrintVertices();
    
    graph.GetNextEdges(5);
    
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
